/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:33:37 by dydaniel          #+#    #+#             */
/*   Updated: 2024/12/07 23:25:26 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_store_extra(char *temp_text)
{
	char	*store_text;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!temp_text || temp_text[0] == '\0')
		return (free(temp_text), NULL);
	while (temp_text[j] != '\n' && temp_text[j] != '\0')
		j++;
	if (temp_text[j] == '\n')
		j++;
	while (temp_text[j + i] != '\0')
		i++;
	store_text = malloc(sizeof(char) * (i + 1));
	if (store_text == NULL || i == 0)
		return (free(temp_text), free(store_text), NULL);
	i = 0;
	while (temp_text[j + i] != '\0')
	{
		store_text[i] = temp_text[j + i];
		i++;
	}
	store_text[i] = '\0';
	return (free(temp_text), store_text);
}

int	ft_linebreak_in(char *text)
{
	int	i;

	i = 0;
	if (!text)
		return (0);
	while (*text)
	{
		if (*text == '\n')
			return (1);
		text++;
	}
	return (0);
}
