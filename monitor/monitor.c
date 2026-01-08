/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:49:02 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/08 17:48:32 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"

static int	is_dead(t_philo *philo)
{
	int philo_dead;
	
	pthread_mutex_lock(&philo->last_meal_time_lock);
	philo_dead = get_time() - philo->last_meal_time >= philo->args->time_to_die;
	pthread_mutex_unlock(&philo->last_meal_time_lock);
	return (philo_dead);
}


static void	*monitor_routine(void *m)
{
	t_monitor	*monitor;
	t_list		*current_philo;
	t_philo		*philo;

	monitor = (t_monitor *)m;
	while (1)
	{
		current_philo = monitor->philo_list;
		while (current_philo)
		{
			philo = (t_philo *)current_philo->content;
			if (is_dead(philo))
			{
				sim_print_action(philo->sim, "%zu %d died\n", philo->philo_id);
				mark_sim_over(monitor->sim);
				return ((void *)0);	
			}
			current_philo = current_philo->next;
		}
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

