/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:28:52 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/07 15:53:48 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

#include "../philosopher/philo.h"

typedef struct s_monitor
{
	pthread_t		thread_id;
	t_list			*philo_list;
	t_simulation	*sim;
}	t_monitor;

t_monitor	*create_monitor(t_list *philo_list, t_simulation *sim);
int			start_monitor(t_monitor *monitor);
#endif