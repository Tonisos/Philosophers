/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:13:13 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/16 09:28:38 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long long)1000) + (time.tv_usec / 1000));
}

unsigned long long	ft_time_from_start(t_philo *philo)
{
	return ((ft_get_time() - philo->data->start));
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
