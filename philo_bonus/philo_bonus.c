/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:44:31 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 17:52:08 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	int		*args;
	t_data	data;
	int		i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (errors(1), -1);
	args = type_converter(ac, av);
	if (args == NULL)
		return (-2);
	while (i < 5)
	{
		if (args[i] < -1 || args[0] == 0)
			return (errors(1), free(args), -3);
		i++;
	}
	init_data(&data, args);
	if (data.n_times_eat == 0)
		return (free(args), 1);
	init_structs(args[0], &data);
	usleep(600000);
	sem_unlink("/fork");
	sem_unlink("/death");
	free(args);
}

void	locking_forks(t_philo *philo, sem_t *forks)
{
	long	time;

	sem_wait(forks);
	sem_wait(forks);
	if (get_bool(philo->philex, &philo->data->kill_switch) == false)
	{
		time = get_time()
			- get_long(philo->philex, &philo->data->start);
		sem_wait(philo->death);
		printf("%ld %d has taken a fork\n", time, philo->id);
		printf("%ld %d has taken a fork\n", time, philo->id);
		sem_post(philo->death);
	}
}

void	unlocking_forks(sem_t *forks)
{
	sem_post(forks);
	sem_post(forks);
}
