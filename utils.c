/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:13:13 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/05 14:21:53 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



long long ft_get_time()
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int ft_time_from_start(t_philo *philo)
{
	return((ft_get_time() - philo->data->start));
}

long int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (2147483648);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (2147483648);
		result = result * 10 + *str - '0';
		str++;
	}
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		return (2147483648);
	return ((long)(result * sign));
}
