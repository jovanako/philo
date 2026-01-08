/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:54:06 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/08 17:34:19 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ph)
{
	t_philo	*philo;
	int 	i;
	
	philo = (t_philo *)ph;
	i = 0;
	update_last_meal_time(philo);
	while (philo->args->num_meals == 0 || i < philo->args->num_meals)
	{
		if (is_sim_over(philo->sim))
			return ((void *)NULL);
		philo_eat(philo);
		unlock_second_fork(philo);
		if (&philo->fork_l != philo->fork_r)
			unlock_first_fork(philo);
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
		if (pthread_create(&current_philo->thread_id, NULL, &routine, current_philo) != 0)
			return (print_error_and_return("Failed to create thread\n", 0));
		current_philo_node = current_philo_node->next;
	}
	return (1);
}
