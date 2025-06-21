/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:43:53 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/24 14:45:28 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*nxt;

	if (!lst || !del)
		return ;
	aux = *lst;
	while (aux != NULL)
	{
		nxt = aux->next;
		del(aux->content);
		free(aux);
		aux = nxt;
	}
	*lst = NULL;
}
