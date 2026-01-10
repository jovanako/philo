/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:28:52 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/09 19:32:46 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

#include "../philosopher/philo.h"
#include "../simulation/simulation.h"
#include <unistd.h>

typedef struct s_monitor
{
	pthread_t		thread_id;
	t_list			*philo_list;
	t_simulation	*sim;
}	t_monitor;

t_monitor	*create_monitor(t_list *philo_list, t_simulation *sim);
int			all_done_eating(t_monitor *monitor);
int			someone_died(t_monitor *monitor);
int			start_monitor(t_monitor *monitor);
int			clean_up_monitor_fail(t_args *a, t_simulation *s, t_list *p_list);
#endif
