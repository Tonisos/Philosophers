/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:39:30 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/11 14:12:10 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_error(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if ((int)ft_atoi(argv[1]) == -1 || ft_atoi(argv[2]) < 2)
		return (0);
	if ((int)ft_atoi(argv[2]) == -1)
		return (0);
	if ((int)ft_atoi(argv[3]) == -1)
		return (0);
	if ((int)ft_atoi(argv[4]) == -1)
		return (0);
	if (argc == 6)
	{
		if ((int)ft_atoi(argv[5]) == -1)
			return (0);
	}
	return (1);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->nbr_philo)
			pthread_mutex_destroy (&data->forks[i++]);
		free (data->forks);
	}
	i = 0;
	if (data->threads)
	{
		while (i < data->nbr_philo)
			pthread_detach(data->threads[i++]);
		free (data->threads);
	}
	i = 0;
	// if (data->philos)
	// {
	// 	while (i < data->nbr_philo)
	// 		free(&data->philos[i++]);
	// 	free (data->philos);
	// }
	// pthread_mutex_destroy (&data->wait);
	// free(data);
}
	
// 	// // free les treads
// 	// // free les struct de philo
// 	// // free les fourchettes
	

// }