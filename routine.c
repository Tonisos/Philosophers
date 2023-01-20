/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:44:05 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/20 12:41:38 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{	
	pthread_mutex_lock(&philo->dead);
	philo->last_meal = ft_get_time();
	
	// pthread_detach(death);
	philo->nbr_meal += 1;
	pthread_mutex_lock(&philo->data->wait);
	printf(YELLOW "%llu %d is eating\n" BLEU,
		ft_time_from_start(philo), philo->position);
	pthread_mutex_unlock(&philo->data->wait);
	pthread_mutex_unlock(&philo->dead);
}

void	ft_forks(t_philo *philo, int *fork1, int *fork2)
{

	*fork1 = philo->position;
	*fork2 = (((philo->position) + 1) % philo->data->nbr_philo);
	if (*fork2 == 0)
		*fork2 = philo->data->nbr_philo;
}

void	ft_take_fork(t_philo *philo, int fork)
{
	// pthread_mutex_lock(&philo->dead);

	pthread_mutex_lock(&philo->data->forks[fork - 1]);
	pthread_mutex_lock(&philo->data->wait);
	printf(ROUGE"%llu %d has taken a fork %d\n" ROUGE,
		ft_time_from_start(philo), philo->position, fork);
	pthread_mutex_unlock(&philo->data->wait);
	// pthread_mutex_unlock(&philo->dead);
}

void	ft_drop_the_fork(t_philo *philo, int fork1, int fork2)
{
	pthread_mutex_unlock(&philo->data->forks[fork1 - 1]);
	pthread_mutex_unlock(&philo->data->forks[fork2 - 1]);
	pthread_mutex_lock(&philo->data->wait);
	// printf("---%d---\n", fork2 - 1);
	printf(BLEUCLAIR"%llu %d is sleeping\n",
		ft_time_from_start(philo), philo->position);
	pthread_mutex_unlock(&philo->data->wait);
	ft_usleep(philo->data->time_to_spleep);
	pthread_mutex_lock(&philo->data->wait);
	printf(GREEN"%llu %d is thinking\n",
		ft_time_from_start(philo), philo->position);
	pthread_mutex_unlock(&philo->data->wait);
}

void	*ft_check_death(void *arg)
{
	t_philo		*philo;
	
	philo = (t_philo *) arg;
	printf("%lld\n", ft_time_from_start(philo));
	ft_usleep(philo->data->time_to_die + 1);
	
	pthread_mutex_lock(&philo->data->eat);
	if(ft_get_time() - philo->last_meal > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->finish);
		philo->data->stop = philo->position;
		pthread_mutex_unlock(&philo->data->finish);
	}
	pthread_mutex_unlock(&philo->data->eat);
	return (NULL);
}


void	*ft_routine(void *arg)
{
	pthread_t death;
	t_philo				*philo;
	int					fork1;
	int					fork2;

	philo = (t_philo *) arg;
	ft_forks(philo, &fork1, &fork2);
	while(1)
	{
		pthread_mutex_lock(&philo->data->begin);
		if (philo->data->ready)
		{
			pthread_mutex_unlock(&philo->data->begin);
			break ;
		}
		pthread_mutex_unlock(&philo->data->begin);
		
	}
	philo->last_meal = ft_get_time();
	if (philo->position % 2 == 0)
		ft_usleep((philo->data->time_to_eat / 10));
		
	while (1)
	{
		// printf("%lld\n", ft_time_from_start(philo));
		// ft_usleep(100);
		
		pthread_create(&death, NULL, ft_check_death, &philo->data->philos[philo->position - 1]);
		pthread_detach(death);
		// printf("<<<>>>>\n");
		ft_take_fork(philo, fork1);
		ft_take_fork(philo, fork2);
		eat(philo);
		ft_usleep(philo->data->time_to_eat);
		ft_drop_the_fork(philo, fork1, fork2);
	}
	return (NULL);
}
