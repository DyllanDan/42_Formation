/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:12:23 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/15 15:34:28 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

static int	ft_strncmp_pos(const char *s1, const char *s2, size_t len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
		len--;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_lit;

	len_lit = 0;
	while (little[len_lit] != '\0')
		len_lit++;
	if (!(*little))
		return ((char *)big);
	while (*big && len > 0)
	{
		if (len < len_lit)
			return (0);
		if (ft_strncmp_pos(big, little, len_lit) == 1)
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
