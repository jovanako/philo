/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:42:15 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/09 13:05:09 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	request_seat(t_simulation *sim, long num_philos)
{
	while (1)
	{
		pthread_mutex_lock(&sim->currently_eating_lock);
		if (sim->currently_eating < num_philos - 1 || num_philos == 1)
		{
			sim->currently_eating++;
			pthread_mutex_unlock(&sim->currently_eating_lock);
			return ;
		}	
		pthread_mutex_unlock(&sim->currently_eating_lock);
		usleep(10);
	}
}

void	release_seat(t_simulation *sim)
{
	pthread_mutex_lock(&sim->currently_eating_lock);
	sim->currently_eating--;
	pthread_mutex_unlock(&sim->currently_eating_lock);
}