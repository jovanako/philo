/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:31:39 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/12 11:25:20 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"

static int	is_dead(t_philo *philo)
{
	int		philo_dead;
	long	current_time;

	pthread_mutex_lock(&philo->last_meal_time_lock);
	current_time = get_time();
	philo_dead = current_time - philo->last_meal_time 
		>= philo->args->time_to_die;
	pthread_mutex_unlock(&philo->last_meal_time_lock);
	return (philo_dead);
}

int	all_done_eating(t_monitor *monitor)
{
	t_list	*current_philo;
	t_philo	*philo;

	current_philo = monitor->philo_list;
	while (current_philo)
	{
		philo = (t_philo *)current_philo->content;
		if (!is_done_eating(philo))
			return (0);
		current_philo = current_philo->next;
	}
	return (1);
}

int	someone_died(t_monitor *monitor)
{
	t_list		*current_philo;
	t_philo		*philo;

	current_philo = monitor->philo_list;
	while (current_philo)
	{
		philo = (t_philo *)current_philo->content;
		if (is_dead(philo))
		{
			sim_print_action(philo->sim, "%zu %d died\n", philo->philo_id);
			mark_sim_over(monitor->sim);
			return (1);
		}
		current_philo = current_philo->next;
	}
	return (0);
}
