/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:24:21 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/15 18:12:08 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*temp;
	char	uniq;
	int		i;

	uniq = (char)c;
	temp = (char *)s;
	i = 0;
	while (*s)
	{
		if (*s == uniq)
			return (temp + i);
		s++;
		i++;
	}
	if (*s == uniq)
		return (temp + i);
	return (0);
}
