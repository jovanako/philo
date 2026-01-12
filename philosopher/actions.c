/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:39:03 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/12 11:26:36 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_done_eating(t_philo *philo)
{
	int	done_eating;

	pthread_mutex_lock(&philo->last_meal_time_lock);
	done_eating = philo->args->num_meals != 0
		&& philo->num_times_ate >= philo->args->num_meals;
	pthread_mutex_unlock(&philo->last_meal_time_lock);
	return (done_eating);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_time_lock);
	philo->last_meal_time = get_time();
	philo->num_times_ate++;
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
	lock_second_fork(philo);
	update_last_meal_time(philo);
	if (is_sim_over(philo->sim))
		return ;
	sim_print_action(philo->sim, "%zu %d has taken a fork\n", philo->philo_id);
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
	usleep(1000);
}
