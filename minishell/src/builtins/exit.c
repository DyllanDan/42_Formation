/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 22:06:29 by dydaniel          #+#    #+#             */
/*   Updated: 2025/08/11 22:06:32 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **parser_i)
{
	int	exit_code;

	if (parser_i[2])
	{
		perror("too many arguments");
		exit(1);
	}
	else if (parser_i[1])
	{
		exit_code = ft_atoi_base(parser_i[1], 10);
		if (exit_code > 0)
			exit(exit_code);
		else if (exit_code < 0)
			exit(156);
		else
		{
			perror("numeric argument required");
			exit(2);
		}
	}
	exit(1);
	return (0);
}
