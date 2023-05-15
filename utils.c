/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:57:07 by amontalb          #+#    #+#             */
/*   Updated: 2023/03/29 13:31:57 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long long)1000) + (time.tv_usec / 1000));
}

unsigned long long	ft_time_from_start(void)
{
	static long long	begin = 0;

	if (!begin)
		begin = ft_get_time();
	return (ft_get_time() - begin);
}

unsigned long long	ft_atoi(const char *str)
{
	unsigned long long	result;

	result = 0;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			return (-1);
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		result = result * 10 + *str - '0';
		str++;
	}
	if (result > __LONG_LONG_MAX__)
		return (-1);
	return (result);
}

void	ft_usleep(unsigned long long ms)
{
	unsigned long long	time;

	time = ft_get_time();
	while (ft_get_time() - time < ms)
		usleep(ms / 10);
}

int	ft_print(char *str, t_philo *philo)
{
	int	status;

	pthread_mutex_lock(&philo->data->wait);
	status = philo->data->status;
	philo->status = status;
	if (ft_strncmp(str, "is eating", 9) == 0)
	{
		philo->last_meal = ft_time_from_start();
		philo->nbr_meal++;
	}
	if (status)
		printf("%lld %d %s\n", ft_time_from_start(), philo->position + 1, str);
	pthread_mutex_unlock(&philo->data->wait);
	return (status);
}
