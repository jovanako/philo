/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:38:39 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/09 19:25:11 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	del(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	pthread_mutex_destroy(&(philo->fork_l));
	pthread_mutex_destroy(&(philo->last_meal_time_lock));
	free(philo);
}

void	clean_up_philos(t_list *philo_list)
{
	ft_lstclear(&philo_list, del);
}

void	*clean_up_nodes(t_list *philo_list)
{
	if (philo_list)
		clean_up_philos(philo_list);	
	return (NULL);
}