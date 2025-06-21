/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:58:52 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/21 14:58:35 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	s = (const char *)src;
	d = (unsigned char *)dest;
	if (s == NULL && d == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
