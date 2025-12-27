/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:54:06 by jkovacev          #+#    #+#             */
/*   Updated: 2025/12/27 19:15:07 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time()
{
	struct	timeval tv;
	long	seconds;
	long	microseconds;
	
	gettimeofday(&tv, NULL);
	seconds = tv.tv_sec;
	microseconds = tv.tv_usec;
	return (seconds * 1000 + microseconds / 1000);	
}

int		check_args(t_philo *philo, long num_philos)
{
	// not sure what arg values should be invalid
	if (num_philos < 1 || philo->time_to_die <= 0
		|| philo->time_to_eat <= 0 || philo->time_to_sleep < 0
		|| philo->number_of_times_each_philosopher_must_eat < 0)
		{
			write(2, "Invalid args\n", 13);
			return (0);
		}
	return (1);
}

void	get_philo_values(t_philo *philo, char *argv[])
{
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		philo->number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	else
		philo->number_of_times_each_philosopher_must_eat = 0;
}

int	main(int argc, char *argv[])
{
	long	num_philos;
	long	num_forks;
	t_philo	*philo;
	t_list	*philo_list;
	int		i;

	if (argc < 5 || argc > 6)
		return (print_error_and_return("Invalid args\n", 1));
	// should num_philos and num_forks be inside the structure?
	num_philos = ft_atol(argv[1]);
	num_forks = num_philos;
	
	// create philosopher structure
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (print_error_and_return("Failed malloc\n", 1));
	get_philo_values(philo, argv);
	philo_list = NULL;
	
	// check for invalid args
	if (!check_args(philo, num_philos))
		return (1);

	// set "eat times" if they are 0
	if (philo->number_of_times_each_philosopher_must_eat == 0)
		philo->number_of_times_each_philosopher_must_eat = 5;
	
	// create the correct number of philosophers
	i = 0;
	while (i < num_philos)
	{
		philo_list = ft_lstnew(philo);
		philo->philo_id = i + 1;
		i++;		
	}
	printf("Num philos is: %zu\nTime to die: %zu\nTime to eat: %zu\nTime to sleep: %zu\nEat times: %zu\n", num_philos, philo->time_to_die, philo->time_to_eat, philo->time_to_sleep, philo->number_of_times_each_philosopher_must_eat);
	return (0);
}
