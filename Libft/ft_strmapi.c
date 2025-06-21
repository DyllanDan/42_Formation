/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:49:00 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/21 14:42:49 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_mpd;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	str_mpd = malloc(sizeof(char) * len + 1);
	if (str_mpd == NULL)
		return (NULL);
	while (i < len)
	{
		str_mpd[i] = f(i, s[i]);
		i++;
	}
	str_mpd[i] = '\0';
	return (str_mpd);
}
