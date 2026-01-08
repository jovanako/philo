/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:39:03 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/08 17:33:16 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_time_lock);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->last_meal_time_lock);
}

void	philo_eat(t_philo *philo)
{
	lock_first_fork(philo);
	sim_print_action(philo->sim, "%zu %d has taken a fork\n", philo->philo_id);
	if (philo->args->num_philos == 1)
	{
		usleep(philo->args->time_to_die * 1000);	
		return ;
	}
	if (is_sim_over(philo->sim))
		return ;
	lock_second_fork(philo);
	sim_print_action(philo->sim, "%zu %d has taken a fork\n", philo->philo_id);
	if (is_sim_over(philo->sim))
		return ;
	update_last_meal_time(philo);
	if (is_sim_over(philo->sim))
		return ;
	sim_print_action(philo->sim, "%zu %d is eating\n", philo->philo_id);
	usleep(philo->args->time_to_eat * 1000);
}

void	philo_sleep(t_philo *philo)
{
	sim_print_action(philo->sim, "%zu %d is sleeping\n", philo->philo_id);
	usleep(philo->args->time_to_sleep * 1000);	
}

void	philo_think(t_philo *philo)
{
	sim_print_action(philo->sim, "%zu %d is thinking\n", philo->philo_id);
}