/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:45:10 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 11:20:24 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>

typedef struct s_data
{
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_times_eat;
	int				n_philos;
	long long		start;
	long long		current;
	int				feds;
	bool			ok;
	bool			kill_switch;
	sem_t			*forks;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		philo_routine;
	t_data			*data;
	bool			fed;
	int				meals;
	long long		last_m;
	int				time_left;
	pid_t			pid;
	sem_t			*philex;
	sem_t			*death;
}	t_philo;

int			ft_atoi(char *num);
void		init_data(t_data *data, int *args);
void		init_structs(int n_of_philos, t_data *data);
int			init_philos(t_philo *philos, int n_of_philos, t_data *data);
void		process(t_philo *philo, t_data *data);
int			*type_converter(int ac, char **av);
void		eating(t_philo *philo, int id);
void		sleeping(t_philo *philo, int id);
void		thinking(t_philo *philo, int id);
void		errors(int code);
void		locking_forks(t_philo *philo, sem_t *forks);
void		unlocking_forks(sem_t *forks);
long long	get_time(void);
void		monitoring(t_philo *philos);
void		*routine(void *arg);

/* ************************************************************************** */
/*                             PHILO_UTILS_2_BONUS                            */
/* ************************************************************************** */

void		set_int(sem_t *philo, int value, int *info);
int			get_int(sem_t *philo, int *info);
void		set_long(sem_t *philo, long long value, long long *info);
long long	get_long(sem_t *philo, long long *info);
void		set_bool(sem_t *philo, bool value, bool *info);
bool		get_bool(sem_t *philo, bool *info);
int			ft_usleep(long long milliseconds);
void		*routine_alt(void *arg);

#endif
