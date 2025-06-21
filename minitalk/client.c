/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:03:14 by dydaniel          #+#    #+#             */
/*   Updated: 2025/04/09 20:27:06 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_response_val = 0;

void	response(int signal)
{
	(void)signal;
	g_response_val = 1;
}

void	killing_func(int pid, char *str)
{
	int	bit;

	while (*str != '\0')
	{
		bit = 8;
		while (bit--)
		{
			g_response_val = 0;
			if ((*str) >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (g_response_val == 0)
				;
		}
		str++;
	}
	bit = 8;
	while (bit--)
	{
		g_response_val = 0;
		kill(pid, SIGUSR1);
		while (g_response_val == 0)
			;
	}
}

int	main(int argc, char **argv)
{
	int		num;
	char	*str;

	if (argc != 3)
		return (ft_printf("Not sufficient arguments!\n"), 0);
	num = ft_atoi_base(argv[1], 10);
	if (num <= 0)
		return (ft_printf("Invalid PID!\n"), 0);
	if (kill(num, 0) == -1)
		return (ft_printf("No process with this PID.\n"), 0);
	str = argv[2];
	signal(SIGUSR1, response);
	signal(SIGUSR2, response);
	killing_func(num, str);
	return (0);
}
