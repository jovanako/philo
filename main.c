/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:19:21 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/09 22:08:41 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input/input.h"
#include "lists/lists.h"
#include "philosopher/philo.h"
#include "helpers/helpers.h"
#include "simulation/simulation.h"
#include "monitor/monitor.h"

static int	clean_up_all(t_args *a, t_simulation *s, t_list *p, t_monitor *m)
{
	free(a);
	delete_sim(s);
	clean_up_philos(p);
	free(m);
	return (1);
}

int	join_threads(t_list *philo_list, t_monitor *monitor)
{
	t_philo	*philo;
	
	while(philo_list)
	{
		philo = (t_philo *)philo_list->content;
		if (pthread_join(philo->thread_id, NULL) != 0)
			return (print_error_and_ret("Failed to join philo thread\n", 0));
		philo_list = philo_list->next;
	}
	if (pthread_join(monitor->thread_id, NULL) != 0)
		return (print_error_and_ret("Failed to join monitor thread\n", 0));
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
	printf("num: %ld\n", args->num_philos);
	sim = create_sim();
	if (!sim)
		return (delete_args(args));
	philo_list = create_philo_list(args, sim);
	if (!philo_list)
		return (clean_up_philo_fail(args, sim));
	monitor = create_monitor(philo_list, sim);
	if (!monitor)
		return (clean_up_monitor_fail(args, sim, philo_list));
	sim->start_time = get_time();
	if (!start_philos(philo_list)
		|| !start_monitor(monitor)
		|| !join_threads(philo_list, monitor))
		return (clean_up_all(args, sim, philo_list, monitor));
	clean_up_all(args, sim, philo_list, monitor);
	return (0);
}
