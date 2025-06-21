/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:33:41 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/21 13:38:46 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	if (dest < src)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		s += n - 1;
		d += n - 1;
		while (n--)
		{
			*d-- = *s-- ;
		}
	}
	return (dest);
}
