/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:59:51 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/21 14:40:53 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_charwrt(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		sign;

	num = n;
	sign = 1;
	if (num < 0)
	{
		sign *= -1;
		num *= -1;
		ft_charwrt('-', fd);
	}
	if (num <= 9)
		ft_charwrt('0' + num, fd);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_charwrt('0' + (num % 10), fd);
	}
}
