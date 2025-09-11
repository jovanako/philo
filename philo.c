/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:54:06 by jkovacev          #+#    #+#             */
/*   Updated: 2025/09/11 21:31:21 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time()
{
	struct	timeval tv;
	long	seconds;
	long	microseconds;
	
	gettimeofday(&tv, NULL);
	seconds = tv.tv_sec;
	microseconds = tv.tv_usec;
	return (seconds * 1000 + microseconds / 1000);	
}

int	main(long number_of_philosophers, long time_to_die, long time_to_eat,
	long time_to_sleep, long number_of_times_each_philosopher_must_eat)
{
	if (!number_of_times_each_philosopher_must_eat)
		number_of_times_each_philosopher_must_eat = 5;
	return (0);
}