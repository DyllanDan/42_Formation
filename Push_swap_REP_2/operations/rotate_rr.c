/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:18:11 by dydaniel          #+#    #+#             */
/*   Updated: 2025/03/29 18:30:18 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotator(t_stack **s)
{
	t_stack	*last;
	t_stack	*aux_last;

	aux_last = NULL;
	last = NULL;
	if (!s || !*s || !(*s)->nxt)
		return ;
	aux_last = *s;
	while (aux_last->nxt && aux_last->nxt->nxt)
	{
		aux_last = aux_last->nxt;
	}
	last = aux_last->nxt;
	aux_last->nxt = NULL;
	last->nxt = *s;
	*s = last;
}

void	rra(t_stack **a)
{
	r_rotator(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	r_rotator(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	r_rotator(a);
	r_rotator(b);
	ft_printf("rrr\n");
}
