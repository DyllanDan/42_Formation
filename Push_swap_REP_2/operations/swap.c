/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:15:33 by dydaniel          #+#    #+#             */
/*   Updated: 2025/03/29 18:29:40 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaper(t_stack **s)
{
	t_stack	*aux_1;
	t_stack	*aux_2;

	if (!s)
		return ;
	aux_1 = *s;
	aux_2 = (*s)->nxt;
	aux_1->nxt = aux_2->nxt;
	aux_2->nxt = aux_1;
	*s = aux_2;
}

void	sa(t_stack **a)
{
	swaper(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swaper(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swaper(a);
	swaper(b);
	ft_printf("ss\n");
}
