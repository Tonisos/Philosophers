/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:05:25 by amontalb          #+#    #+#             */
/*   Updated: 2023/03/29 13:32:01 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1 && s2) || (!s2 && s1))
		return (-1);
	while (i < n - 1 && (s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	if (n && n != i)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
