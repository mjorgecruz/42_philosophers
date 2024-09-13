/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:52:44 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 11:00:11 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_int(sem_t *philo, int value, int *info)
{
	sem_wait(philo);
	*info = value;
	sem_post(philo);
}

int	get_int(sem_t *philo, int *info)
{
	int	value;

	sem_wait(philo);
	value = *info;
	sem_post(philo);
	return (value);
}

void	set_long(sem_t *philo, long long value, long long *info)
{
	sem_wait(philo);
	*info = value;
	sem_post(philo);
}

long long	get_long(sem_t *philo, long long *info)
{
	long long	value;

	sem_wait(philo);
	value = *info;
	sem_post(philo);
	return (value);
}
