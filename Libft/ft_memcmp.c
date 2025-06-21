/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:51:01 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/15 14:11:33 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	int					i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		n--;
		i++;
	}
	return (0);
}
