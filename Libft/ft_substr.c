/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:43:10 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/24 10:56:04 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	j;

	i = ft_strlen(s);
	j = 0;
	if (len > i - start)
		len = i - start;
	if (start > i)
		len = 0;
	sub_s = malloc(len + 1);
	if (sub_s == NULL)
		return (NULL);
	if (start >= i)
	{
		sub_s[j] = '\0';
		return (sub_s);
	}
	while (j < i && j < len)
	{
		sub_s[j] = s[start + j];
		j++;
	}
	sub_s[j] = '\0';
	return (sub_s);
}
