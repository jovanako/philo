/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:37:44 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/09 20:11:55 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

long	ft_atol(char *nptr);
int		ft_strlen(char *s);
int		print_error_and_ret(char *s, int ret);
long	get_time();
int		ft_is_alpha(char *s);
#endif