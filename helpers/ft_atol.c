/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:06:01 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/09 22:14:48 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <limits.h>

static int	ft_isdigit(char c)
{
	if (!(c >= '0' && c <= '9'))
		return(0);
	return (1);
}

static int	remove_special_characters(char *n)
{
	int	i;

	i = 0;
	while (n[i] == ' ' || (n[i] >= 9 && n[i] <= 13))
		i++;
	return (i);
}

long	ft_atol(char *nptr)
{
	int		i;
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	i = remove_special_characters(nptr);
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((i < ft_strlen(nptr)) && ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		if (result > INT_MAX)
			return (-1);
		i++;
	}
	result *= sign;
	return (result);
}
