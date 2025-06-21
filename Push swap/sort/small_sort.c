/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:28:58 by dydaniel          #+#    #+#             */
/*   Updated: 2025/03/29 19:41:01 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_is_lower(t_stack *a, int size)
{
	int	num;

	num = a->num;
	while (a && size)
	{
		if (num > a->num)
			return (0);
		a = a->nxt;
		size--;
	}
	return (1);
}

int	f_is_higher(t_stack *a, int size)
{
	int	num;

	num = a->num;
	while (a && size)
	{
		if (num < a->num)
			return (0);
		a = a->nxt;
		size--;
	}
	return (1);
}

void	sort_3(t_stack **a)
{
	if ((*a)->num < (*a)->nxt->num && (*a)->num < (*a)->nxt->nxt->num)
		sa(a);
	if ((*a)->num > (*a)->nxt->nxt->num && (*a)->nxt->num < (*a)->nxt->nxt->num)
		ra(a);
	else if ((*a)->num > (*a)->nxt->num && (*a)->num < (*a)->nxt->nxt->num)
		sa(a);
	else if ((*a)->num < (*a)->nxt->num && (*a)->num > (*a)->nxt->nxt->num)
		rra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

void	sort_4(t_stack **a, t_stack **b, int size)
{
	while (!is_sorted(*a))
	{
		if (f_is_lower(*a, size))
		{
			pb(a, b);
			sort_3(a);
			pa(a, b);
			break ;
		}
		if (f_is_higher(*a, size))
		{
			pb(a, b);
			sort_3(a);
			pa(a, b);
			ra(a);
			break ;
		}
		ra(a);
	}
}

void	sort_5(t_stack **a, t_stack **b, int size)
{
	while (!is_sorted(*a))
	{
		if (f_is_lower(*a, size))
		{
			pb(a, b);
			sort_4(a, b, size);
			pa(a, b);
			break ;
		}
		if (f_is_higher(*a, size))
		{
			pb(a, b);
			sort_4(a, b, size);
			pa(a, b);
			ra(a);
			break ;
		}
		ra(a);
	}
}
