/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:42:52 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/05 17:35:10 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*get_philo_args(char *argv[])
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->num_philos = ft_atol(argv[1]);
	args->time_to_die = ft_atol(argv[2]);
	args->time_to_eat = ft_atol(argv[3]);
	args->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		args->number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	else
		args->number_of_times_each_philosopher_must_eat = 0;
	return (args);
}

int		philo_init(t_philo **philo, t_args *args)
{
	*philo = malloc(sizeof(t_philo));
	if (!(*philo))
		return (print_error_and_return("Failed malloc\n", 0));
	(*philo)->args = args;
	(*philo)->fork_l = malloc(sizeof(t_fork));
	if (!((*philo)->fork_l))
		return (print_error_and_return("Failed malloc\n", 0));
	pthread_mutex_init(&(*philo)->fork_l->mutex, NULL);
	(*philo)->fork_l->fork = 1;
	return (1);
}

t_list	*create_philo_list(t_args *args)
{
	t_philo	*philo;
	t_list	*philo_list;
	t_fork	*previous_fork;
	int		i;

	philo = NULL;
	philo_list = NULL;
	previous_fork = NULL;
	i = 0;
	while (i < args->num_philos)
	{
		if (!philo_init(&philo, args))
			return (NULL); // print error
		ft_lstadd_back(&philo_list, ft_lstnew(philo));
		//check if node is NULL
		philo->philo_id = i + 1;
		if (previous_fork)
			philo->fork_r = previous_fork;
		previous_fork = philo->fork_l;
		i++;
	}
	((t_philo *)philo_list->content)->fork_r = previous_fork;
	return (philo_list);
}
