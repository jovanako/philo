/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:54:06 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/04 18:31:51 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_args	*args;
	t_list	*philo_list;
	
	if (argc < 5 || argc > 6)
		return (print_error_and_return("Invalid args\n", 1));
	args = get_philo_args(argv);
	if (!args)
		return (print_error_and_return("Failed malloc\n", 1));
	if (!check_args(args))
		return (1);
	philo_list = create_philo_list(args);
	if (!philo_list)
		return (print_error_and_return("Failed philosopher list init\n", 1));
	if (!thread_loop(philo_list, args))
		return (1);
	return (0);
}
