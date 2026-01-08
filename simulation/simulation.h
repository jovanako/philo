/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 08:49:30 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/08 20:50:00 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../helpers/helpers.h"

typedef struct simulation
{
	int				is_over;
	long			start_time;
	pthread_mutex_t	state_lock;
	pthread_mutex_t	stdout_lock;
	long			currently_eating;
	pthread_mutex_t	currently_eating_lock;
}	t_simulation;

t_simulation	*create_sim();
void			free_sim(t_simulation *sim);
void			sim_print_action(t_simulation *sim, char *msg, int philo_id);
int				is_sim_over(t_simulation *sim);
void			mark_sim_over(t_simulation *sim);
void			request_seat(t_simulation *sim, long num_philos);
void			release_seat(t_simulation *sim);
#endif