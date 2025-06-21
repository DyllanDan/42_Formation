/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:00:57 by dydaniel          #+#    #+#             */
/*   Updated: 2025/05/17 14:48:44 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(int i)
{
	if (i == 1)
		printf("Wrong arguments!\n");
	if (i == 2)
		printf("To many philosophers!\n");
	if (i == 3)
		printf("Impossible to get real time.\n");
	if (i == 4)
		printf("Needed at least one philo to proceed.\n");
	if (i == 5)
		printf("Only non-zero positive numbers are accepted.\n");
	return (0);
}

int	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1])
	{
		j = 0;
		while ((argv[i + 1][j]))
		{
			if (!ft_isdigit((argv[i + 1][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_values(t_argv values)
{
	int	i;

	i = 1;
	if (values.argv1 == 0)
		i = error(4);
	if (values.argv1 > MAX_PHILO)
		i = error(2);
	return (i);
}
