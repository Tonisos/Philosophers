/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:20:33 by amontalb          #+#    #+#             */
/*   Updated: 2023/01/06 10:14:54 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BLEUCLAIR "\033[01;34m"
#define ROUGE "\033[00;31m"
#define BLEU "\033[00;34m"
#define NORMAL "\033[00m"


typedef struct s_philo{
	
	int 				position;
	unsigned long long	last_meal;
	int					nbr_meal;
	struct s_data *data;
}t_philo;

typedef struct s_data{
	
	unsigned long long	start;
	int					nbr_philo;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_spleep;
	int	nbr_meal;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_t			*threads;
	pthread_mutex_t		wait;
	
}t_data;

int					ft_check_error(int argc, char **argv);
unsigned long long	ft_get_time();
unsigned long long	ft_atoi(const char *str);
int					ft_init(t_data *data, int argc, char **argv);
void				*ft_routine(void *arg);
int					ft_init_threads_forks(t_data *data);
unsigned long long	ft_time_from_start(t_philo *philo);

#endif