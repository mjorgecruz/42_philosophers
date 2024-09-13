/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:26:07 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 17:51:00 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_data(t_data *data, int *args)
{
	(*data).n_philos = args[0];
	(*data).t_die = args[1];
	(*data).t_eat = args[2];
	(*data).t_sleep = args[3];
	(*data).n_times_eat = args[4];
	(*data).feds = 0;
	(*data).kill_switch = false;
	(*data).ok = false;
}

void	init_structs(int n_of_philos, t_data *data)
{
	int		i;
	t_philo	*philos;
	sem_t	*forks;
	sem_t	*death;

	philos = (t_philo *)malloc(sizeof(t_philo) * n_of_philos);
	if (philos == NULL)
		return ;
	sem_unlink("/fork");
	sem_unlink("/death");
	forks = sem_open("/fork", O_CREAT, 0600, n_of_philos);
	sem_close(forks);
	death = sem_open("/death", O_CREAT, 0600, 1);
	sem_close(death);
	i = 0;
	while (i < n_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].meals = 0;
		philos[i].fed = false;
		i++;
	}
	init_philos(philos, n_of_philos, data);
	free(philos);
}

int	init_philos(t_philo *philos, int n_of_philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < n_of_philos)
	{
		philos[i].pid = fork();
		if (philos[i].pid == -1)
			return (printf("Error in creating processes"), 0);
		if (philos[i].pid == 0)
			return (process(&philos[i], data), 1);
		i++;
	}
	while (1)
	{
		if (waitpid(-1, NULL, WNOHANG) != 0)
		{
			i = 0;
			while (i < n_of_philos - 1)
				kill(philos[i++].pid, SIGINT);
			return (1);
		}
	}
}
