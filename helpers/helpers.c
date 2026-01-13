/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:05:07 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/12 19:32:38 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
	}
	return (len);
}

int	print_error_and_ret(char *s, int ret)
{
	write(2, s, ft_strlen(s));
	return (ret);
}

long	get_time(void)
{
	struct timeval	tv;
	long			seconds;
	long			microseconds;

	gettimeofday(&tv, NULL);
	seconds = tv.tv_sec;
	microseconds = tv.tv_usec;
	return (seconds * 1000 + microseconds / 1000);
}

int	ft_is_alpha(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 97 && s[i] <= 122)
			|| (s[i] >= 65 && s[i] <= 90))
			return (1);
		i++;
	}
	return (0);
}
