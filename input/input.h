/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:30:37 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/09 18:05:37 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../helpers/helpers.h"

typedef struct s_args
{
	long	num_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	num_meals;
}	t_args;

t_args	*parse_args(int argc, char *argv[]);
int		delete_args(t_args *args);
#endif
