/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_locking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:26:09 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/08 17:31:33 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void lock_first_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
		pthread_mutex_lock(&philo->fork_l);
	else	
		pthread_mutex_lock(philo->fork_r);
}

void lock_second_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
		pthread_mutex_lock(philo->fork_r);
	else	
		pthread_mutex_lock(&philo->fork_l);
}

void unlock_first_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
		pthread_mutex_unlock(&philo->fork_l);
	else	
		pthread_mutex_unlock(philo->fork_r);
}

void unlock_second_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
		pthread_mutex_unlock(philo->fork_r);
	else	
		pthread_mutex_unlock(&philo->fork_l);
}
