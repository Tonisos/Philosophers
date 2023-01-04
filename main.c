/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:18:12 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/04 18:13:00 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data data;
	
	// if (!ft_check_error(argc, argv))
	// 	return (0);
	if (!ft_init(&data, argc, argv))
		return (0);
	usleep(10000);
	//initialiser routine
	//initialiser boucle avant fin
	//free all;
	return (0);

}