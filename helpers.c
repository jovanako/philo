/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:05:07 by jkovacev          #+#    #+#             */
/*   Updated: 2025/12/26 20:18:03 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
	}
	return (len);
}

int	print_error_and_return(char *s, int ret)
{
	write(2, s, ft_strlen(s));
	return (ret);
}