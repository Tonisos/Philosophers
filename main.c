/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:18:12 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/05 14:29:04 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int ft_to_finnish(t_data *data)
{
	int	i;
	int compt;

	while (1)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
			if ((ft_get_time() - data->philos[i].last_meal) > data->time_to_die)
			{
				pthread_mutex_unlock(&data->wait);
				printf(NORMAL"[%d] Philosopher number %d died\n", ft_time_from_start(&data->philos[i]), data->philos[i].position);
				exit (0);
			}
			i++;
		}
		i = 0;
		compt = 0;
		while (i < data->nbr_philo)
		{
			if(data->philos[i].nbr_meal == data->nbr_meal)
				compt ++;
			if (compt == data->nbr_philo)
			{
				printf("Tout le monde a graille a sa faim\n");
				exit (0);

			}
			i++;
		}
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_data data;
	
	// if (!ft_check_error(argc, argv))
	// 	return (0);
	if (!ft_init(&data, argc, argv))
		return (0);
	ft_to_finnish(&data);
	usleep(10000000);
	
	//initialiser boucle avant fin
	//free all;
	return (0);
}