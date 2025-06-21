/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:20:15 by dydaniel          #+#    #+#             */
/*   Updated: 2025/04/09 20:32:36 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	mensage_print(char **str, char *c, int *bit, siginfo_t *info)
{
	char	*temp;

	if (*c == 0)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*c = 0;
		*bit = 0;
		*str = NULL;
		kill(info->si_pid, SIGUSR2);
		return (0);
	}
	temp = ft_strjoin(*str, c);
	free(*str);
	*str = temp;
	*c = 0;
	*bit = 0;
	return (1);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static char	*str = NULL;
	static int	bit = 0;

	context = NULL;
	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	if (str == NULL)
		str = ft_strdup("");
	bit++;
	if (bit == 8)
	{
		if (mensage_print(&str, &c, &bit, info) == 0)
			return ;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	if (pid < 0)
		return (ft_printf("PID didn't get.\n"), 0);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}
