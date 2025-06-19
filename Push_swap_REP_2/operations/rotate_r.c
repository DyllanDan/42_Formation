/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:17:15 by dydaniel          #+#    #+#             */
/*   Updated: 2025/03/31 22:02:05 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotator(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	first = *s;
	*s = (*s)->nxt;
	last = *s;
	while (last->nxt != NULL)
		last = last->nxt;
	last->nxt = first;
	first->nxt = NULL;
}

void	ra(t_stack **a)
{	
	rotator(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotator(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotator(a);
	rotator(b);
	ft_printf("rr\n");
}
