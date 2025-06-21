/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:09:50 by dydaniel          #+#    #+#             */
/*   Updated: 2025/04/05 16:29:18 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_stack	*aux;

	while (a)
	{
		aux = a;
		a = a->nxt;
		free(aux);
	}
}

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

int	check_error(char **splitted)
{
	if (!check_args(splitted))
		return (ft_printf("ERROR\n"), 0);
	else if (!check_rep(splitted))
		return (ft_printf("ERROR\n"), 0);
	return (1);
}
