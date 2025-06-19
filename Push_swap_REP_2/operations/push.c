/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:19:54 by dydaniel          #+#    #+#             */
/*   Updated: 2025/03/29 18:30:39 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pusher(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;

	if (!a || !(*a))
		return ;
	aux_a = (*a);
	(*a) = aux_a->nxt;
	aux_a->nxt = (*b);
	*b = aux_a;
}

void	pa(t_stack **a, t_stack **b)
{
	pusher(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	pusher(a, b);
	ft_printf("pb\n");
}
