/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:39:30 by amontalb          #+#    #+#             */
/*   Updated: 2023/03/27 13:01:54 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_error(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if ((int)ft_atoi(argv[1]) == -1 || ft_atoi(argv[1]) < 1)
		return (0);
	if ((int)ft_atoi(argv[2]) == -1)
		return (0);
	if ((int)ft_atoi(argv[3]) == -1)
		return (0);
	if ((int)ft_atoi(argv[4]) == -1)
		return (0);
	if (argc == 6)
	{
		if ((int)ft_atoi(argv[5]) <= 0)
			return (0);
	}
	return (1);
}
