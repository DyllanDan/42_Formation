/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:34:47 by dydaniel          #+#    #+#             */
/*   Updated: 2025/03/29 19:39:26 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bit_number(int len_stack)
{
	int	binary;

	binary = 1;
	while (len_stack > 1)
	{
		len_stack = len_stack / 2;
		binary++;
	}
	return (binary);
}

t_stack	*get_min(t_stack **a)
{
	t_stack	*aux;
	t_stack	*min;
	int		has_min;

	aux = *a;
	has_min = 0;
	min = NULL;
	if (aux)
	{
		while (aux)
		{
			if ((aux->index == -1) && (!has_min || aux->num < min->num))
			{
				min = aux;
				has_min = 1;
			}
			aux = aux->nxt;
		}
	}
	return (min);
}

void	convert_index(t_stack **a)
{
	t_stack	*aux_a;
	int		index;

	index = 0;
	if (!a && !*a)
		return ;
	aux_a = get_min(a);
	while (aux_a)
	{
		aux_a->index = index++;
		aux_a = get_min(a);
	}
}

void	big_sort(t_stack **a, t_stack **b, int size)
{
	int	bit_shift;
	int	index_count;
	int	i;

	index_count = bit_number(size - 1);
	bit_shift = 0;
	while (bit_shift < index_count)
	{
		i = size;
		while (i != 0)
		{
			if (!(((*a)->index >> bit_shift) & 1))
				pb(a, b);
			else
				ra(a);
			i--;
		}
		while (*b && b)
			pa(a, b);
		bit_shift++;
	}
}
