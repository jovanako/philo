/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:37:13 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/09 20:22:26 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static int	invalid_args(t_args *args)
{
	// not sure what arg values should be invalid
	if (args->num_philos < 1 || args->num_philos > 200 
		|| args->time_to_die < 0 || args->time_to_eat < 0
		|| args->time_to_sleep < 0 || args->num_meals < 0)
		{
			write(2, "Invalid args\n", 13);
			free(args);
			return (1);
		}
	return (0);
}

int	delete_args(t_args *args)
{
	free(args);
	return (1);
}

static int	check_if_alpha(char *argv[])
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_alpha(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	*error_and_ret(char *err)
{
	write(2, err, ft_strlen(err));
	return (NULL);
}

t_args	*parse_args(int argc, char *argv[])
{
	t_args	*args;

	if (argc < 5 || argc > 6)
		return (error_and_ret("Invalid number of args\n"));
	if (check_if_alpha(argv))
		return (error_and_ret("Invalid args\n"));
	args = malloc(sizeof(t_args));
	if (!args)
	{
		write(2, "Failed args malloc\n", 19);
		return (NULL);
	}
	args->num_philos = ft_atol(argv[1]);
	args->time_to_die = ft_atol(argv[2]);
	args->time_to_eat = ft_atol(argv[3]);
	args->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		args->num_meals = ft_atol(argv[5]);
	else
		args->num_meals = 0;
	if (invalid_args(args))
		return (NULL);
	return (args);
}
