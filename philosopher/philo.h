/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:29:16 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/08 17:32:31 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include "../input/input.h"
#include "../lists/lists.h"
#include "../simulation/simulation.h"

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	t_simulation	*sim;
	t_args			*args;
	long			last_meal_time;
	pthread_mutex_t last_meal_time_lock;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	*fork_r;
}	t_philo;

t_list	*create_philo_list(t_args *args, t_simulation *sim);
int		start_philos(t_list *philo_list);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	clean_up_philos(t_list *philo_list);
void	update_last_meal_time(t_philo *philo);
void	lock_first_fork(t_philo *philo);
void	lock_second_fork(t_philo *philo);
void	unlock_first_fork(t_philo *philo);
void	unlock_second_fork(t_philo *philo);
#endif