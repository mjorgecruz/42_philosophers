/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:45:19 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 10:11:43 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_int(pthread_mutex_t *mutex, int value, int *info)
{
	pthread_mutex_lock(mutex);
	*info = value;
	pthread_mutex_unlock(mutex);
}

int	get_int(pthread_mutex_t *mutex, int *info)
{
	int	value;

	pthread_mutex_lock(mutex);
	value = *info;
	pthread_mutex_unlock(mutex);
	return (value);
}

void	set_long(pthread_mutex_t *mutex, long long value, long long *info)
{
	pthread_mutex_lock(mutex);
	*info = value;
	pthread_mutex_unlock(mutex);
}

long long	get_long(pthread_mutex_t *mutex, long long *info)
{
	long long	value;

	pthread_mutex_lock(mutex);
	value = *info;
	pthread_mutex_unlock(mutex);
	return (value);
}
