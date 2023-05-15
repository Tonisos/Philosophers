/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:20:08 by amontalb          #+#    #+#             */
/*   Updated: 2023/03/29 13:32:45 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define BLEUCLAIR "\033[01;34m"
# define ROUGE "\033[00;31m"
# define BLEU "\033[00;34m"
# define NORMAL "\033[00m"
# define YELLOW "\033[33m"
# define GREEN "\033[32m"
# define GRAY "\033[2;37m"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					nbr_philo;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_spleep;
	int					nbr_meal;
	int					end;
	int					status;
	pthread_mutex_t		wait;
	pthread_t			*threads;
	t_philo				*philos;
}t_data;

struct s_philo
{
	int					position;
	unsigned long long	last_meal;
	int					nbr_meal;
	int					status;
	t_data				*data;
	pthread_mutex_t		fork;
};

int					ft_check_error(int argc, char **argv);
unsigned long long	ft_get_time(void);
unsigned long long	ft_atoi(const char *str);
unsigned long long	ft_time_from_start(void);
void				ft_usleep(unsigned long long ms);
int					ft_print(char *str, t_philo *philo);
int					ft_init(t_data *data, int argc, char **argv);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_routine(t_philo *philo);

#endif