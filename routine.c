/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   routine.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amontalb <amontalb@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/22 10:55:29 by amontalb		  #+#	#+#			 */
/*   Updated: 2023/03/29 13:21:41 by amontalb		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

static int	ft_eat(t_philo *philo)
{
	int	status;

	status = ft_print("is eating", philo);
	if (status)
		ft_usleep(philo->data->time_to_eat);
	return (!status);
}

static int	ft_sleep(t_philo *philo)
{
	int	status;

	status = ft_print("is sleeping", philo);
	if (status)
		ft_usleep(philo->data->time_to_spleep);
	return (!status);
}

void	ft_exit(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->data->philos[(philo->position + 1)
		% philo->data->nbr_philo].fork);
}

void	ft_routine(t_philo *philo)
{
	while ((philo->nbr_meal != philo->data->nbr_meal
			|| philo->data->nbr_meal == -1) && philo->status)
	{
		if (!ft_print("is thinking", philo))
			break ;
		if (philo->position % 2 == 0)
			usleep(philo->data->nbr_philo * 100);
		pthread_mutex_lock(&philo->fork);
		if (!ft_print("has taken a fork", philo))
			return ((void) pthread_mutex_unlock(&philo->fork));
		if (philo->data->nbr_philo > 1)
			pthread_mutex_lock(&philo->data->philos[(philo->position + 1)
				% philo->data->nbr_philo].fork);
		else
			return ((void) pthread_mutex_unlock(&philo->fork));
		if (!ft_print("has taken a fork", philo))
			return (ft_exit(philo));
		if (ft_eat(philo))
			return (ft_exit(philo));
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->data->philos[(philo->position + 1)
			% philo->data->nbr_philo].fork);
		if (ft_sleep(philo))
			break ;
	}
}
