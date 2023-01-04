/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:39:30 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/04 10:11:58 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_error(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (ft_atoi(argv[1]) == 2147483648 || ft_atoi(argv[2]) < 2)
		return (0);
	if (ft_atoi(argv[2]) == 2147483648)
		return (0);
	if (ft_atoi(argv[3]) == 2147483648)
		return (0);
	if (ft_atoi(argv[4]) == 2147483648)
		return (0);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) == 2147483648)
			return (0);
	}
	return (1);
}