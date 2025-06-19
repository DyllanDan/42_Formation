/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:05:31 by dydaniel          #+#    #+#             */
/*   Updated: 2025/03/29 19:35:53 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*aux;

	aux = a;
	if (size_stack(aux) == 1)
		return (1);
	while (aux)
	{
		if (aux->nxt && aux->num > aux->nxt->num)
			return (0);
		aux = aux->nxt;
	}
	return (1);
}

void	sort_2(t_stack **a)
{
	if ((*a)->num > (*a)->nxt->num)
		sa(a);
	else
		return ;
}

void	small_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 3)
		sort_3(a);
	if (size == 4)
		sort_4(a, b, size);
	if (size == 5)
		sort_5(a, b, size);
}

void	sort_maker(t_stack **a, t_stack **b, int size)
{
	if (is_sorted(*a))
		return ;
	else if (size == 2)
		sort_2(a);
	else if (size > 2 && size <= 5)
		small_sort(a, b, size);
	else
	{
		convert_index(a);
		big_sort(a, b, size);
	}
}
