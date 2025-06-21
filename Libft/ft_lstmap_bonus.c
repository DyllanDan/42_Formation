/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:54:41 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/28 11:37:51 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create(void *data)
{
	t_list	*new_node;

	new_node = NULL;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = data;
	new_node->next = NULL;
	return (new_node);
}

void	ft_clear_lst_nd(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	temp = *lst;
	while (temp->next != NULL)
	{
		next = temp->next;
		del(temp->content);
		free(temp);
		temp = next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*aux;

	if (!f || !del || !lst)
		return (NULL);
	new_lst = ft_create(f(lst->content));
	if (new_lst == NULL)
		return (NULL);
	aux = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_create(f(lst->content));
		if (!new_lst->next)
		{
			ft_clear_lst_nd(&aux, del);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	new_lst->next = NULL;
	return (aux);
}
