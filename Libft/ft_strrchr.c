/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:59:04 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/21 14:39:45 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		p;
	char	*temp;
	char	uniq;

	temp = (char *)s;
	uniq = (char)c;
	i = 0;
	p = -1;
	while (*s)
	{
		if (*s == uniq)
			p = i;
		i++;
		s++;
	}
	if (*s == uniq)
		return (temp + i);
	if (p < 0)
		return (NULL);
	else
		return (temp + p);
}
