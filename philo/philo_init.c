/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:46:18 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 12:29:05 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int *args)
{
	(*data).n_philos = args[0];
	(*data).t_die = args[1];
	(*data).t_eat = args[2];
	(*data).t_sleep = args[3];
	(*data).n_times_eat = args[4];
	(*data).kill_switch = false;
	(*data).feds = 0;
	(*data).ok = false;
	pthread_mutex_init(&((*data).data), NULL);
}

void	init_threads(t_philo *philos, int n_of_philos, t_data *data)
{
	int	i;

	i = 0;
	init_structs(philos, n_of_philos, data);
	if (n_of_philos < 2 || data->n_times_eat == 0)
	{
		f_condition(philos, data);
		return ;
	}
	while (i < n_of_philos)
	{
		if (pthread_create(&philos[i].philo, NULL, &routine, &philos[i]) != 0)
			return ;
		i++;
	}
	set_bool(&data->data, true, &(data->ok));
	while (get_bool(&data->data, &philos->data->kill_switch) == false)
	{
		set_long(&data->data, get_time(), &(data->current));
		monitoring(philos);
		if (get_int(&data->data, &data->feds) == data->n_philos)
			set_bool(&data->data, true, &(data->kill_switch));
	}
}

void	init_structs(t_philo *philos, int n_of_philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].meals = 0;
		philos[i].fed = false;
		philos[i].data->kill_switch = false;
		philos[i].last_m = get_time();
		philos[i].start_time = get_time();
		if (i == n_of_philos - 1)
			philos[i].right_fork = &philos[0].left_fork;
		else
			philos[i].right_fork = &philos[i + 1].left_fork;
		pthread_mutex_init(&philos[i].left_fork, NULL);
		i++;
	}
}

int	f_condition(t_philo *philos, t_data *data)
{
	if (data->n_philos == 0)
		return (errors(5), 0);
	if (data->n_times_eat == 0)
		return (0);
	if (data->n_philos == 1)
	{
		pthread_create(&philos[0].philo, NULL, &routine_alt, &philos[0]);
	}
	while (get_bool(&data->data, &philos->data->kill_switch) == false)
	{
		set_long(&data->data, get_time(), &(data->current));
		monitoring(philos);
		if (get_int(&data->data, &data->feds) == data->n_philos)
			set_bool(&data->data, true, &(data->kill_switch));
	}
	return (1);
}

void	*routine_alt(void *arg)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *) arg;
	set_long(&philo->data->data, get_time(), &philo->start_time);
	set_long(&philo->data->data, get_time(), &(philo->last_m));
	time = get_time()
		- get_long(&(philo->data->data), &philo->start_time);
	printf("%lld %d has taken a fork\n", time, 1);
	return (NULL);
}
