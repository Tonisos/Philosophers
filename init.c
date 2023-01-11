/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:15:32 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/11 14:30:25 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	ft_init_philos(t_data *data, int i)
{
	t_philo	philo;

	philo.last_meal = ft_get_time();
	philo.nbr_meal = 0;
	philo.position = i + 1;
	philo.data = data;
	pthread_mutex_init(&philo.dead, NULL);
	return (philo);
}

int	ft_init_threads_forks(t_data *data)
{
	int	i;

	i = 0;
	data->threads = malloc(sizeof(pthread_t) * data->nbr_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	data->philos = malloc (sizeof(t_philo) * data->nbr_philo);
	pthread_mutex_init(&data->wait, NULL);
	if (!data->threads || !data->forks || !data->philos)
		return (1);
	while (i < data->nbr_philo)
	{
		data->philos[i] = ft_init_philos(data, i);
		pthread_create(&data->threads[i], NULL, ft_routine, &data->philos[i]);
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

int	ft_init(t_data *data, int argc, char **argv)
{
	data->start = ft_get_time();
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_spleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_meal = ft_atoi(argv[5]);
	else
		data->nbr_meal = -1;
	if (ft_init_threads_forks(data))
		return (1);
	return (0);
}
