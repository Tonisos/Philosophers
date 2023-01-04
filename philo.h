/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:20:33 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/04 18:15:16 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



typedef struct s_philo{
	
	int position;
	int	last_meal;
	int nbr_meal;
	struct s_data *t_data;
}t_philo;

typedef struct s_data{
	
	long long		start;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_spleep;
	int				nbr_meal;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	pthread_mutex_t	wait;
	
}t_data;

int			ft_check_error(int argc, char **argv);
int 		ft_get_time();
long int	ft_atoi(const char *str);
int			ft_init(t_data *data, int argc, char **argv);
void		*ft_routine(t_philo *philo);
int			ft_init_threads_forks(t_data *data);


#endif