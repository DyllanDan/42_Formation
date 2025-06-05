/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:07:41 by dydaniel          #+#    #+#             */
/*   Updated: 2024/11/20 16:59:50 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexconverter(unsigned long num, int *count, char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num <= 15)
	{
		if (c == 'x' || c == 'p')
			ft_putchar(hex[num % 16], count);
		else if (c == 'X')
			ft_putchar(ft_toupper(hex[num % 16]), count);
	}
	else
	{
		ft_hexconverter(num / 16, count, c);
		if (c == 'x' || c == 'p')
			ft_putchar(hex[num % 16], count);
		else if (c == 'X')
			ft_putchar(ft_toupper(hex[num % 16]), count);
	}
}

void	ft_puthex(unsigned long num, int *count, char c)
{
	if (num == 0 && c != 'p')
	{
		ft_putstr("0", count);
		return ;
	}
	else if (num == 0 && c == 'p')
	{
		ft_putstr("(nil)", count);
		return ;
	}
	if (c == 'p')
		ft_putstr("0x", count);
	ft_hexconverter(num, count, c);
}
