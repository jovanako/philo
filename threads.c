/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:20:25 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/05 17:11:45 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ph)
{
	t_philo	*philo;
	int 	i;
	
	philo = (t_philo *)ph;
	i = 0;
	while (philo->args->number_of_times_each_philosopher_must_eat == 0
		|| i < philo->args->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&philo->fork_l->mutex);
		printf("%zu %d has taken a fork\n", get_time(), philo->philo_id);
		pthread_mutex_lock(&philo->fork_r->mutex);
		printf("%zu %d is eating\n", get_time(), philo->philo_id);
		usleep(philo->args->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->fork_r->mutex);
		pthread_mutex_unlock(&philo->fork_l->mutex);
		printf("%zu %d is sleeping\n", get_time(), philo->philo_id);
		usleep(philo->args->time_to_sleep * 1000);
		printf("%zu %d is thinking\n", get_time(), philo->philo_id);
		i++;
	}
	return ((void *)NULL);
}

int	thread_loop(t_list *philo_list, t_args *args)
{
	pthread_t	*thread_array;
	t_list		*current_philo;
	int 		i;

	current_philo = philo_list;
	thread_array = malloc(args->num_philos * sizeof(pthread_t));
	if (!thread_array)
		return (print_error_and_return("Failed malloc\n", 0));
	i = 0;
	while (i < args->num_philos)
	{
		if (pthread_create(thread_array + i, NULL, &routine, current_philo->content) != 0)
			return (print_error_and_return("Failed to create thread\n", 0));
		i++;
		current_philo = current_philo->next;
	}
	i = 0;
	while (i < args->num_philos)
	{
		if (pthread_join(thread_array[i], NULL) != 0)
			return (print_error_and_return("Failed to join thread\n", 0));
		i++;
	}
	// clean up philosophers
	free(thread_array);
	return (1);
}
