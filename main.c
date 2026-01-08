/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:19:21 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/08 20:04:29 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input/input.h"
#include "lists/lists.h"
#include "philosopher/philo.h"
#include "helpers/helpers.h"
#include "simulation/simulation.h"
#include "monitor/monitor.h"

int	join_threads(t_list *philo_list, t_monitor *monitor)
{
	t_philo	*philo;
	
	while(philo_list)
	{
		philo = (t_philo *)philo_list->content;
		if (pthread_join(philo->thread_id, NULL) != 0)
			return (print_error_and_return("Failed to join philo thread\n", 0));
		philo_list = philo_list->next;
	}
	if (pthread_join(monitor->thread_id, NULL) != 0)
		return (print_error_and_return("Failed to join monitor thread\n", 0));
	return (1);
}

int	main(int argc, char *argv[])
{
	t_args			*args;
	t_list			*philo_list;
	t_simulation	*sim;
	t_monitor		*monitor;	
	
	args = parse_args(argc, argv);
	if (!args)
		return (1);
	sim = create_sim();
	if (!sim)
		return (1);
	philo_list = create_philo_list(args, sim);
	if (!philo_list)
		return (print_error_and_return("Failed philosopher list init\n", 1));
	monitor = create_monitor(philo_list, sim);
	if (!monitor)
		return (1);
	sim->start_time = get_time();
	if (!start_philos(philo_list))
		return (1);
	if (!start_monitor(monitor))
		return (1);
	if (!join_threads(philo_list, monitor))
		return (1);
	// clean_up_philos(philo_list); - clean up everything on every exit
	return (0);
}
