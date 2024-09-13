/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_4_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:59:47 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 11:02:49 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_bool(sem_t *philo, bool value, bool *info)
{
	sem_wait(philo);
	*info = value;
	sem_post(philo);
}

bool	get_bool(sem_t *philo, bool *info)
{
	bool	value;

	sem_wait(philo);
	value = *info;
	sem_post(philo);
	return (value);
}

int	ft_usleep(long long milliseconds)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) <= milliseconds)
		usleep(500);
	return (0);
}
