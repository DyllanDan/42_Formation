/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:42:46 by dydaniel          #+#    #+#             */
/*   Updated: 2025/03/29 19:49:13 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = 0;
	stack->index = -1;
	stack->nxt = NULL;
	return (stack);
}

void	populate_stack(char **argv, t_stack *a)
{
	t_stack	*aux;

	aux = a;
	while (*(argv))
	{
		aux->num = (int)ft_atoi_base(*argv, 10);
		if (*(argv + 1))
		{
			aux->nxt = create_stack();
			aux = aux->nxt;
		}
		argv++;
	}
}

int	size_stack(t_stack *a)
{
	int		i;
	t_stack	*aux_a;

	i = 0;
	aux_a = a;
	while (aux_a)
	{
		aux_a = aux_a->nxt;
		i++;
	}
	return (i);
}
