/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:15:32 by amontalb          #+#    #+#             */
/*   Updated: 2023/03/29 14:37:24 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_data(t_data *data, int argc, char **argv)
{
	t_philo		*philos;
	int			i;

	i = -1;
	pthread_mutex_init(&data->wait, NULL);
	philos = NULL;
	data->status = 1;
	data->threads = NULL;
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_spleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nbr_meal = ft_atoi(argv[5]);
	else
		data->nbr_meal = -1;
	data->threads = (pthread_t *) malloc(sizeof(pthread_t) * data->nbr_philo);
	philos = (t_philo *) malloc(sizeof(t_philo) * data->nbr_philo);
	data->philos = philos;
	if (data->philos == NULL || data->threads == NULL)
		return (1);
	while (++i < data->nbr_philo)
		pthread_mutex_init(&philos[i].fork, NULL);
	return (0);
}

int	ft_init(t_data *data, int argc, char **argv)
{
	int			i;

	i = -1;
	if (ft_init_data(data, argc, argv))
		return (1);
	ft_time_from_start();
	while (++i < data->nbr_philo)
	{
		data->philos[i].position = i;
		data->philos[i].last_meal = 0;
		data->philos[i].status = 1;
		data->philos[i].data = data;
		data->philos[i].nbr_meal = 0;
		pthread_create(&data->threads[i], NULL, (void *)
			ft_routine, &data->philos[i]);
	}
	return (0);
}
