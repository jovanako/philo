/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:36:24 by jkovacev          #+#    #+#             */
/*   Updated: 2025/12/27 18:37:34 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*del_and_free(void *content, t_list **result, void (*del)(void *))
{
	del(content);
	ft_lstclear(result, del);
	return (NULL);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (lst)
	{
		while (last->next)
			last = last->next;
	}
	return (last);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		if (lst->content != NULL)
			del(lst->content);
		free(lst);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;
	void	*new_content;

	if (!lst)
		return (NULL);
	new_content = f(lst->content);
	result = ft_lstnew(new_content);
	if (result == NULL)
	{
		del(new_content);
		return (NULL);
	}
	node = result;
	lst = lst->next;
	while (lst)
	{
		new_content = f(lst->content);
		node->next = ft_lstnew(new_content);
		if (node->next == NULL)
			return (del_and_free(new_content, &result, del));
		node = node->next;
		lst = lst->next;
	}
	return (result);
}
