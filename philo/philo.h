/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:52:04 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 10:07:29 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_data
{
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_times_eat;
	int				n_philos;
	long long		current;
	bool			kill_switch;
	int				feds;
	pthread_mutex_t	data;
	bool			ok;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	t_data			*data;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	bool			fed;
	int				meals;
	long long		last_m;
	int				time_left;
	long long		start_time;
}	t_philo;

/* ************************************************************************** */
/*                                 PHILO                                      */
/* ************************************************************************** */
int			*type_converter(int ac, char **av);
void		*routine(void *arg);
void		locking_forks(t_philo *philo);
void		unlocking_forks(t_philo *philo);

/* ************************************************************************** */
/*                              PHILO_UTILS                                   */
/* ************************************************************************** */
int			ft_atoi(char *num);
void		eating(t_philo *philo, int id);
void		sleeping(t_philo *philo, int id);
void		thinking(t_philo *philo, int id);
void		monitoring(t_philo *philos);
long		get_time(void);

/* ************************************************************************** */
/*                             PHILO_UTILS_2                                  */
/* ************************************************************************** */
void		set_int(pthread_mutex_t *mutex, int value, int *info);
void		set_long(pthread_mutex_t *mutex, long long value, long long *info);
void		set_bool(pthread_mutex_t *mutex, bool value, bool *info);
int			get_int(pthread_mutex_t *mutex, int *info);
long long	get_long(pthread_mutex_t *mutex, long long *info);
bool		get_bool(pthread_mutex_t *mutex, bool *info);
int			ft_usleep(long long milliseconds);

/* ************************************************************************** */
/*                              PHILO_ERRORS                                  */
/* ************************************************************************** */
void		errors(int code);

/* ************************************************************************** */
/*                               PHILO_INIT                                   */
/* ************************************************************************** */
void		init_data(t_data *data, int *args);
void		init_threads(t_philo *philos, int n_of_philos, t_data *data);
void		init_structs(t_philo *philos, int n_of_philos, t_data *data);
int			f_condition(t_philo *philos, t_data *data);
void		*routine_alt(void *arg);

/* ************************************************************************** */
/*                              PHILO_FINEX                                   */
/* ************************************************************************** */
void		finex_threads(t_philo *philos, t_data *data);

#endif
