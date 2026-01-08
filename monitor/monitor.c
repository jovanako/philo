/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:49:02 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/08 19:50:42 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"

static void	*monitor_routine(void *m)
{
	t_monitor	*monitor;

	monitor = (t_monitor *)m;
	while (1)
	{
		if (someone_died(monitor) || all_done_eating(monitor))
			return ((void *)0);
		usleep(100);
	}
	return ((void *)0);
}

t_monitor	*create_monitor(t_list *philo_list, t_simulation *sim)
{
	t_monitor	*monitor;

	monitor = malloc(sizeof(t_monitor));
	if (!monitor)
	{
		write(2, "Failed monitor malloc\n", 22);
		return (NULL);
	}
	monitor->philo_list = philo_list;
	monitor->sim = sim;
	return (monitor);
}

int	start_monitor(t_monitor *monitor)
{
	char *error_message;

	error_message = "Failed to create monitor thread\n";
	if (pthread_create(&monitor->thread_id, NULL, &monitor_routine, monitor))
		return (print_error_and_return(error_message, 0));
	return (1);
}

