/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:27:36 by masoares          #+#    #+#             */
/*   Updated: 2024/01/10 11:27:45 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	errors(int code)
{
	if (code >= 1 && code <= 4)
	{
		printf("Bad formatting: please input:\n"
			"\"./philo <number_of_philosophers> <time_to_die> "
			"<time_to_eat> <time_to_sleep> <[number_of_times_each_"
			"philosopher_must_eat]>\" (all positive integers)\n");
	}
}
