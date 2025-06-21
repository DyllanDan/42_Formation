/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:13:54 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/30 14:24:27 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memcopy_alt(void *dest, const char *str, size_t len)
{
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)dest;
	i = 0;
	while (len--)
	{
		d[i] = str[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	joined = malloc(len1 + len2 + 1);
	if (joined == NULL)
		return (NULL);
	ft_memcopy_alt(joined, s1, len1);
	ft_memcopy_alt(joined + len1, s2, len2);
	joined[len1 + len2] = '\0';
	return (joined);
}
