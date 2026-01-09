/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:42:52 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/09 19:35:07 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_init(t_philo **philo, t_args *args, t_simulation *sim)
{
	*philo = malloc(sizeof(t_philo));
	if (!(*philo))
		return (print_error_and_ret("Failed philo malloc\n", 0));
	(*philo)->args = args;
	(*philo)->sim = sim;
	pthread_mutex_init(&(*philo)->fork_l, NULL);
	(*philo)->last_meal_time = 0;
	(*philo)->num_times_ate = 0;
	pthread_mutex_init(&(*philo)->last_meal_time_lock, NULL);
	return (1);
}

t_list	*create_philo_list(t_args *args, t_simulation *sim)
{
	t_philo			*philo;
	t_list			*philo_list;
	pthread_mutex_t	*previous_fork;
	int				i;

	philo = NULL;
	philo_list = NULL;
	previous_fork = NULL;
	i = 0;
	while (i < args->num_philos)
	{
		if (!philo_init(&philo, args, sim))
			return (NULL);
		if (!ft_lstadd_back(&philo_list, philo))
			return (clean_up_nodes(philo_list));
		philo->philo_id = i + 1;
		if (previous_fork)
			philo->fork_r = previous_fork;
		previous_fork = &(philo->fork_l);
		i++;
	}
	((t_philo *)philo_list->content)->fork_r = previous_fork;
	return (philo_list);
}

int	clean_up_philo_fail(t_args *args, t_simulation *sim)
{
	free(args);
	delete_sim(sim);
	return (print_error_and_ret("Failed philosopher list init\n", 1));
}
