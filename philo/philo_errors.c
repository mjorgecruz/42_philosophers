/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:09:21 by masoares          #+#    #+#             */
/*   Updated: 2024/01/16 12:34:48 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errors(int code)
{
	if (code >= 1 && code <= 4)
	{
		printf("Bad formatting: please input:\n"
			"\"./philo <number_of_philosophers> <time_to_die> "
			"<time_to_eat> <time_to_sleep> <[number_of_times_each_"
			"philosopher_must_eat]>\" (all positive integers)\n");
	}
	if (code == 5)
	{
		printf("Number of philosophers must be bigger than 0: please input:\n"
			"\"./philo <number_of_philosophers> <time_to_die> "
			"<time_to_eat> <time_to_sleep> <[number_of_times_each_"
			"philosopher_must_eat]>\" (all positive integers)\n");
	}
}
