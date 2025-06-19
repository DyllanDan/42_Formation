/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:44:55 by dydaniel          #+#    #+#             */
/*   Updated: 2025/04/05 11:32:18 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	check_space(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(char **split)
{
	int		i;
	int		j;
	char	*str;

	str = NULL;
	i = 0;
	j = 0;
	while (split[i])
	{
		j = 0;
		str = split[i];
		while (str[j])
		{
			if (str[j] == '-' || str[j] == '+')
				j++;
			if (!ft_isdigit(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_sign(char **str1, char **str2)
{
	if (*str1[0] == '-' || *str1[0] == '+')
		*str1 += 1;
	if (*str2[0] == '-' || *str2[0] == '+')
		*str2 += 1;
}

int	check_rep(char **splitted)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 0;
	while (splitted[i])
	{
		j = i + 1;
		str1 = splitted[i];
		while (splitted[j])
		{
			str2 = splitted[j];
			if (ft_atoi_base(str1, 10) == ft_atoi_base(str2, 10))
				return (0);
			j++;
		}
		if (ft_atoi_base(splitted[i], 10) > 2147483647 || \
				ft_atoi_base(splitted[i], 10) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**splitted;
	int		size;

	if (!(argc >= 2))
		return (0);
	splitted = argv + 1;
	if (check_space(argv))
	{
		splitted = ft_split(argv[1], ' ');
		if (!check_error(splitted))
			return (free_split(splitted), 0);
	}
	else if (!check_error(splitted))
		return (0);
	a = create_stack();
	b = NULL;
	populate_stack(splitted, a);
	size = size_stack(a);
	sort_maker(&a, &b, size);
	if (argc == 2 && check_space(argv))
		free_split(splitted);
	free_stack(a);
	return (0);
}
