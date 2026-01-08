/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 08:49:42 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/08 18:10:17 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

t_simulation	*create_sim()
{
	t_simulation	*sim;

	sim = malloc(sizeof(t_simulation));
	if (!sim)
	{
		write(2, "Failed sim malloc\n", 18);
		return (NULL);
	}
	sim->is_over = 0;
	pthread_mutex_init(&sim->state_lock, NULL);
	pthread_mutex_init(&sim->stdout_lock, NULL);
	return (sim);
}

void	free_sim(t_simulation *sim)
{
	pthread_mutex_destroy(&sim->state_lock);
	pthread_mutex_destroy(&sim->stdout_lock);
	free(sim);
}

void	sim_print_action(t_simulation *sim, char *msg, int philo_id)
{
	pthread_mutex_lock(&sim->stdout_lock);
	if (!is_sim_over(sim))
		printf(msg, get_time() - sim->start_time, philo_id);
	pthread_mutex_unlock(&sim->stdout_lock);
}

int		is_sim_over(t_simulation *sim)
{
	int	is_over;
	
	pthread_mutex_lock(&sim->state_lock);
	is_over = sim->is_over;
	pthread_mutex_unlock(&sim->state_lock);
	return (is_over);
}

void	mark_sim_over(t_simulation *sim)
{
	pthread_mutex_lock(&sim->state_lock);
	sim->is_over = 1;
	pthread_mutex_unlock(&sim->state_lock);	
}