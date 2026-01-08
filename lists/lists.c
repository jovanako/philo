/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:33:14 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/06 17:35:34 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstadd_back(t_list **lst, void *content)
{
	t_list	*last;
	t_list	*new;
	
	new = ft_lstnew(content);
	if (!new)
		print_error_and_return("Failed malloc\n", 0);
	else
	{
		if (*lst)
		{
			last = *lst;
			while (last->next)
				last = last->next;
			last->next = new;
		}
		else
			*lst = new;		
	}
	return (1);	
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = temp->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
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