/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:18:12 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/11 11:02:36 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_die(t_data *data)
{
	int	i;
	unsigned long long t;

	i = 0;
	
	while (i < data->nbr_philo)
	{
		pthread_mutex_lock(&data->philos[i].dead);
		t = ft_get_time() - data->philos[i].last_meal;
		if (t > data->time_to_die)
		{
			printf("%llu\n", t);
			printf("%llu\n", ft_get_time());
			printf("%llu\n", data->philos[i].last_meal);
			pthread_mutex_lock(&data->wait);
			printf(NORMAL"%llu %d died\n",
				ft_time_from_start(&data->philos[i]), data->philos[i].position);
			return (1);
		}
		pthread_mutex_unlock(&data->philos[i].dead);
		i++;
	}
	return (0);
}

int	ft_full_eat(t_data *data)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	if ((int)data->time_to_eat == -1)
		return (0);
	while (i < data->nbr_philo)
	{
		if (data->philos[i].nbr_meal == data->nbr_meal)
			compt ++;
		if (compt == data->nbr_philo)
		{
			pthread_mutex_lock(&data->wait);
			printf("Every one is full\n");
			return (1);
		}
			i++;
	}
	return (0);
}

void	ft_to_finnish(t_data *data)
{
	while (1)
	{
		if (ft_full_eat(data) || ft_die(data))
		{
			return ;
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_check_error(argc, argv))
	{
		printf("Invalid arguments");
		return (0);
	}
	if (!ft_init(&data, argc, argv))
		return (0);
	usleep(data.time_to_eat);
	ft_to_finnish(&data);
	// usleep(10000);
	// ft_exit(&data);
	return (0);
}
