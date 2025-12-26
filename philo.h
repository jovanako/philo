/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:54:16 by jkovacev          #+#    #+#             */
/*   Updated: 2025/12/26 20:18:20 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef enum e_state
{
	EATING,
	THINKING,
	SLEEPING
}	t_state;

typedef struct s_philo
{
	int		philo_id;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_times_each_philosopher_must_eat;
	int		is_eating;
	int		fork_left;
	int		fork_right;
}	t_philo;

long	ft_atol(char *nptr);
int		ft_strlen(char *s);
int		print_error_and_return(char *s, int ret);
#endif