/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:54:06 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/08 20:34:40 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ph)
{
	t_philo	*philo;
	int 	i;
	
	philo = (t_philo *)ph;
	if (philo->philo_id % 2 == 0)
		usleep(philo->args->time_to_eat / 10);
	i = 0;
	while (!is_done_eating(philo))
	{
		if (is_sim_over(philo->sim))
			return ((void *)NULL);
		philo_eat(philo);
		pthread_mutex_unlock(philo->fork_r);
		if (&philo->fork_l != philo->fork_r)
			pthread_mutex_unlock(&philo->fork_l);
		if (is_sim_over(philo->sim))
			return ((void *)NULL);
		philo_sleep(philo);
		if (is_sim_over(philo->sim))
			return ((void *)NULL);
		philo_think(philo);
		i++;
	}
	return ((void *)NULL);
}

int	start_philos(t_list *philo_list)
{
	t_list		*current_philo_node;
	t_philo		*current_philo;

	current_philo_node = philo_list;
	while (current_philo_node)
	{
		current_philo = (t_philo *)current_philo_node->content;
		update_last_meal_time(current_philo);
		if (pthread_create(&current_philo->thread_id, NULL, &routine, current_philo) != 0)
			return (print_error_and_return("Failed to create thread\n", 0));
		current_philo_node = current_philo_node->next;
	}
	return (1);
}
