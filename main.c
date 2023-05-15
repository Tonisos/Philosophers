/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amontalb <amontalb@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/22 10:55:29 by amontalb		  #+#	#+#			 */
/*   Updated: 2023/03/29 13:16:56 by amontalb		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

static int	check_end(t_philo *philos)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < philos->data->nbr_philo)
	{
		if (philos[i].nbr_meal == philos->data->nbr_meal)
			j++;
		if ((philos[i].last_meal + philos->data->time_to_die)
			< ft_time_from_start()
			|| j == philos->data->nbr_philo)
		{
			if (j != philos->data->nbr_philo)
				printf("%lld %d died\n", ft_time_from_start(),
					philos[i].position + 1);
			philos->data->status = 0;
			return (0);
		}
	}
	return (1);
}

static void	wait_end(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
		pthread_join(data->threads[i], NULL);
}

static void	free_and_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
		pthread_mutex_destroy(&data->philos[i].fork);
	pthread_mutex_destroy(&data->wait);
	if (data->philos != NULL)
		free(data->philos);
	if (data->threads != NULL)
		free(data->threads);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		run;

	run = 1;
	if (!ft_check_error(argc, argv))
	{
		printf("Invalid arguments");
		return (0);
	}
	ft_init(&data, argc, argv);
	run = data.status;
	while (run)
	{
		pthread_mutex_lock(&data.wait);
		run = check_end(data.philos);
		pthread_mutex_unlock(&data.wait);
		usleep(100);
	}
	wait_end(&data);
	free_and_destroy(&data);
	return (0);
}
