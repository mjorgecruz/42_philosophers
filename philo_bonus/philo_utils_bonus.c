/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:13:31 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 12:54:32 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(char *num)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	if (num[0] == '-')
		return (-2);
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
			return (-2);
		n = n * 10;
		n = n + (num[i] - '0');
		i++;
	}
	if (n > INT_MAX)
		return (-2);
	return ((int) n);
}

int	*type_converter(int ac, char **av)
{
	int	*conv_args;
	int	i;

	conv_args = (int *)malloc(sizeof(int) * 6);
	if (conv_args == NULL)
		return (NULL);
	i = 0;
	if (ac == 5)
	{
		conv_args[4] = -1;
		while (i < 4)
		{
			conv_args[i] = ft_atoi(av[i + 1]);
			i++;
		}
	}
	else if (ac == 6)
	{
		while (i < 5)
		{
			conv_args[i] = ft_atoi(av[i + 1]);
			i++;
		}
	}
	return (conv_args);
}

void	process(t_philo *philo, t_data *data)
{
	sem_unlink("/philo");
	philo->philex = sem_open("/philo", O_CREAT, 0600, 1);
	philo->data->forks = sem_open("/fork", 0);
	philo->death = sem_open("/death", 0);
	data->start = get_time();
	philo->last_m = get_time();
	data->current = get_time();
	if (data->n_philos == 1)
		pthread_create(&(philo->philo_routine), NULL, &routine_alt, NULL);
	else
		pthread_create(&(philo->philo_routine), NULL, &routine, philo);
	while (get_bool(philo->philex, &philo->data->kill_switch) == false
		&& (get_bool(philo->philex, &philo->fed) == false))
		monitoring(philo);
	pthread_join((philo->philo_routine), NULL);
	sem_close(philo->philex);
	sem_close(philo->death);
	sem_close(philo->data->forks);
	return ;
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	thinking(philo, (*philo).id);
	while (get_bool(philo->philex, &philo->data->kill_switch) == false)
	{
		if (get_bool(philo->philex, &philo->data->kill_switch) == true)
			return (NULL);
		locking_forks(philo, philo->data->forks);
		eating(philo, (*philo).id);
		unlocking_forks(philo->data->forks);
		sleeping(philo, (*philo).id);
		thinking(philo, (*philo).id);
		if (get_bool(philo->philex, &philo->data->kill_switch) == true 
			|| get_bool(philo->philex, &(philo->fed)) == true)
			return (NULL);
	}
	return (NULL);
}

void	*routine_alt(void *arg)
{
	(void) arg;
	printf("%d %d has taken a fork\n", 0, 1);
	return (NULL);
}
