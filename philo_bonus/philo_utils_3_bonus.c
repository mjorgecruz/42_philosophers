/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:54:52 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 17:41:27 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo, int id)
{
	long long	time;

	time = get_time()
		- get_long(philo->philex, &(philo->data->start));
	if (get_bool(philo->philex, &(philo->data->kill_switch)) == true)
		return ;
	sem_wait(philo->death);
	printf("%lld %d is eating\n", time, id);
	sem_post(philo->death);
	ft_usleep(philo->data->t_eat);
	sem_wait(philo->philex);
	philo->last_m = get_time();
	sem_post(philo->philex);
	philo->meals++;
	if (philo->meals == philo->data->n_times_eat)
		set_bool(philo->philex, true, &(philo->fed));
}

void	sleeping(t_philo *philo, int id)
{
	long long	time;

	time = get_time()
		- get_long(philo->philex, &(philo->data->start));
	if (get_bool(philo->philex, &(philo->data->kill_switch)) == true)
		return ;
	sem_wait(philo->death);
	printf("%lld %d is sleeping\n", time, id);
	sem_post(philo->death);
	ft_usleep(philo->data->t_sleep);
}

void	thinking(t_philo *philo, int id)
{
	long long	time;

	time = get_time()
		- get_long(philo->philex, &(philo->data->start));
	if (get_bool(philo->philex, &(philo->data->kill_switch)) == true)
		return ;
	sem_wait(philo->death);
	printf("%lld %d is thinking\n", time, id);
	sem_post(philo->death);
	ft_usleep(1);
}

long long	get_time(void)
{
	struct timeval	current;
	long			time;

	gettimeofday(&current, NULL);
	time = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (time);
}

void	monitoring(t_philo *philos)
{
	long long	time;

	philos->time_left = get_time()
		- get_long(philos->philex, &(philos->last_m));
	if (get_bool(philos->philex, &philos->fed))
		return ;
	else if (philos->time_left >= philos->data->t_die)
	{
		set_bool(philos->philex, true, &(philos->data->kill_switch));
		time = get_time()
			- get_long(philos->philex, &(philos->data->start));
		sem_wait(philos->death);
		printf("%lld %d died\n", time, philos->id);
		return ;
	}
}
