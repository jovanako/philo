/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:54:16 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/05 17:34:30 by jkovacev         ###   ########.fr       */
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

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_args
{
	long	num_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_times_each_philosopher_must_eat;
}	t_args;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				fork;
}	t_fork;

typedef struct s_philo
{
	int		philo_id;
	t_args	*args;
	t_fork	*fork_l;
	t_fork	*fork_r;
}	t_philo;

long	ft_atol(char *nptr);
int		ft_strlen(char *s);
int		print_error_and_return(char *s, int ret);
long	get_time();
t_args	*get_philo_args(char *argv[]);
int		check_args(t_args *args);
int		philo_init(t_philo **philo, t_args *args);
t_list	*create_philo_list(t_args *args);
int		thread_loop(t_list *philo_list, t_args *args);

// lists
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif