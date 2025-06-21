/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:38:42 by dydaniel          #+#    #+#             */
/*   Updated: 2024/12/07 23:18:05 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (joined == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1 && s1[len1] != '\0')
	{
		joined[len1] = s1[len1];
		len1++;
	}
	while (s2 && s2[len2] != '\0')
	{
		joined[len1 + len2] = s2[len2];
		len2++;
	}
	joined[len1 + len2] = '\0';
	free(s1);
	return (joined);
}

char	*ft_getline(char *temp)
{
	int		i;
	char	*line_get;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\n')
		i++;
	line_get = (char *)malloc(i + 1);
	if (line_get == NULL)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
	{
		line_get[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		line_get[i] = '\n';
		i++;
	}
	line_get[i] = '\0';
	return (line_get);
}

char	*ft_readbuffer(int fd, char *extra)
{
	char		*temp_text;
	ssize_t		bytes_read;

	temp_text = (char *)malloc(BUFFER_SIZE + 1);
	bytes_read = 1;
	while (!ft_linebreak_in(extra) && bytes_read != 0)
	{
		bytes_read = read(fd, temp_text, BUFFER_SIZE);
		if ((int)bytes_read == -1)
			return (free(temp_text), free(extra), NULL);
		if (bytes_read == 0)
			break ;
		temp_text[bytes_read] = '\0';
		extra = ft_strjoin(extra, temp_text);
	}
	free(temp_text);
	return (extra);
}

char	*get_next_line(int fd)
{
	char		*line_read;
	static char	*extra = NULL;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	extra = ft_readbuffer(fd, extra);
	if (!extra || extra[0] == '\0')
		return (NULL);
	line_read = ft_getline(extra);
	extra = ft_store_extra(extra);
	return (line_read);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int i;

	i = open("t.txt", O_RDONLY);
	printf("%s", get_next_line(i));
	return (0);
}