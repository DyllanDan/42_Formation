/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:10:05 by dydaniel          #+#    #+#             */
/*   Updated: 2024/11/05 17:10:08 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnums(long n, int *count, char no_sign)
{
	char	*num_str;

	if (no_sign == 't' && n < 0)
		n *= (-1);
	num_str = ft_itoa_long(n);
	ft_putstr(num_str, count);
	free(num_str);
}
