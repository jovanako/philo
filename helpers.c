/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:05:07 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/05 17:34:44 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
	}
	return (len);
}

int	print_error_and_return(char *s, int ret)
{
	write(2, s, ft_strlen(s));
	return (ret);
}

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

int		check_args(t_args *args)
{
	// not sure what arg values should be invalid
	if (args->num_philos < 1 || args->time_to_die <= 0
		|| args->time_to_eat <= 0 || args->time_to_sleep < 0
		|| args->number_of_times_each_philosopher_must_eat < 0)
		{
			write(2, "Invalid args\n", 13);
			return (0);
		}
	return (1);
}
