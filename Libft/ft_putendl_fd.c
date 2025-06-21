/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:50:34 by dydaniel          #+#    #+#             */
/*   Updated: 2024/10/21 13:32:32 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	char	*lb;
	int		i;

	i = 0;
	lb = "\n";
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, lb, 1);
}
