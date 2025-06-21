/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:34:40 by dydaniel          #+#    #+#             */
/*   Updated: 2024/11/04 16:34:45 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conditionals(const char c, int *count, va_list args)
{
	if (c == 'd')
		ft_putnums((long)va_arg(args, int), count, 'f');
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 'p')
		ft_puthex((unsigned long)va_arg(args, void *), count, 'p');
	else if (c == 'i')
		ft_putnums((long)va_arg(args, int), count, 'f');
	else if (c == 'u')
		ft_putnums((long)va_arg(args, unsigned int), count, 't');
	else if (c == 'x')
		ft_puthex((unsigned long)va_arg(args, unsigned int), count, 'x');
	else if (c == 'X')
		ft_puthex((unsigned long)va_arg(args, unsigned int), count, 'X');
	else if (c == '%')
		ft_putchar('%', count);
	else
		return ;
}

int	ft_printf(const char *argument, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, argument);
	if (!argument)
		return (-1);
	while (*argument)
	{
		if (*argument == '%')
		{
			argument++;
			ft_conditionals(*argument, &count, args);
		}
		else
			ft_putchar(*argument, &count);
		argument++;
	}
	va_end(args);
	return (count);
}
