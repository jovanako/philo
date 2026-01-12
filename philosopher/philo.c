/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:54:06 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/12 11:28:55 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ph)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)ph;
	i = 0;
	while (!is_done_eating(philo))
	{
		if (is_sim_over(philo->sim))
			return (NULL);
		philo_think(philo);
		request_seat(philo->sim, philo->args->num_philos);
		philo_eat(philo);
		unlock_second_fork(philo);
		if (&philo->fork_l != philo->fork_r)
			unlock_first_fork(philo);
		release_seat(philo->sim);
		if (is_sim_over(philo->sim))
			return (NULL);
		philo_sleep(philo);
		i++;
	}
	return (NULL);
}

int	start_philos(t_list *philo_list)
{
	t_list		*current_philo_node;
	t_philo		*current_philo;

	current_philo_node = philo_list;
	while (current_philo_node)
	{
		current_philo = (t_philo *)current_philo_node->content;
		pthread_mutex_lock(&current_philo->last_meal_time_lock);
		current_philo->last_meal_time = get_time();
		pthread_mutex_unlock(&current_philo->last_meal_time_lock);
		if (pthread_create(&current_philo->thread_id, NULL, \
			&routine, current_philo) != 0)
			return (print_error_and_ret("Failed to create thread\n", 0));
		current_philo_node = current_philo_node->next;
	}
	return (1);
}
