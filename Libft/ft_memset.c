/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:33:18 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/21 13:29:45 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	l;
	unsigned char	*str;
	size_t			i;

	i = 0;
	l = c;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = l;
		i++;
	}
	return (s);
}
