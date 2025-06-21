/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:26:09 by dydaniel          #+#    #+#             */
/*   Updated: 2024/12/08 04:48:15 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
char	*ft_store_extra(char *temp_text);
char	*ft_getline(char *temp);
char	*ft_strjoin(char *s1, char *s2);
int		ft_linebreak_in(char *text);
char	*ft_readbuffer(int fd, char *extra);
char	*get_next_line(int fd);

#endif
