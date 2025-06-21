/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:54:40 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/21 14:37:56 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_numlen(int n)
{	
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	*ft_numstr(char *str, long n, int len, int sign)
{
	char	*aux;

	aux = str;
	aux[len] = '\0';
	while (--len >= 0)
	{
		aux[len] = '0' + (n % 10);
		n /= 10;
		if (sign == -1 && len == 0)
			aux[len] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	temp;
	int		len;
	int		sign;

	temp = n;
	sign = 1;
	len = ft_numlen(n);
	if (n < 0)
	{
		temp *= -1;
		sign *= -1;
	}
	if (n == 0)
		len = 1;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_numstr(str, temp, len, sign);
	return (str);
}
