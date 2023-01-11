/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:44:05 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/11 15:28:17 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->dead);
	philo->last_meal = ft_get_time();
	philo->nbr_meal += 1;
	pthread_mutex_lock(&philo->data->wait);
	printf(YELLOW "%llu %d is eating\n" BLEU,
		ft_time_from_start(philo), philo->position);
	pthread_mutex_unlock(&philo->data->wait);
	pthread_mutex_unlock(&philo->dead);
}

void	ft_forks(t_philo *philo, int *fork1, int *fork2)
{
	if (philo->position % 2 != 0)
	{
		*fork1 = philo->position;
		*fork2 = (((philo->position) + 1) % philo->data->nbr_philo);
		if (*fork2 == 0)
			*fork2 = philo->data->nbr_philo;
	}
	else
	{
		*fork2 = philo->position;
		*fork1 = ((philo->position + 1) % philo->data->nbr_philo);
		if (*fork1 == 0)
			*fork1 = philo->data->nbr_philo;
	}
}

void	ft_take_fork(t_philo *philo, int fork)
{
	pthread_mutex_lock(&philo->data->forks[fork - 1]);
	pthread_mutex_lock(&philo->data->wait);
	printf(ROUGE"%llu %d has taken a fork %d\n" ROUGE,
		ft_time_from_start(philo), philo->position, fork);
	pthread_mutex_unlock(&philo->data->wait);
}

void	ft_drop_the_fork(t_philo *philo, int fork1, int fork2)
{
	pthread_mutex_unlock(&philo->data->forks[fork1 - 1]);
	pthread_mutex_unlock(&philo->data->forks[fork2 - 1]);
	pthread_mutex_lock(&philo->data->wait);
	printf(BLEUCLAIR"%llu %d is sleeping\n",
		ft_time_from_start(philo), philo->position);
	pthread_mutex_unlock(&philo->data->wait);
	usleep((philo->data->time_to_spleep * 1000));
	pthread_mutex_lock(&philo->data->wait);
	printf(GREEN"%llu %d is thinking\n",
		ft_time_from_start(philo), philo->position);
	pthread_mutex_unlock(&philo->data->wait);
}

void	*ft_routine(void *arg)
{
	t_philo				*philo;
	int					fork1;
	int					fork2;
	unsigned long long	time;

	philo = (t_philo *) arg;
	ft_forks(philo, &fork1, &fork2);
	while (1)
	{
		ft_take_fork(philo, fork1);
		ft_take_fork(philo, fork2);
		eat(philo);
		time = ft_get_time() + philo->data->time_to_eat - 60;
		while (ft_get_time() <= time)
			;
		ft_drop_the_fork(philo, fork1, fork2);
	}
}
