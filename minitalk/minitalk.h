/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:13:20 by dydaniel          #+#    #+#             */
/*   Updated: 2025/04/09 20:33:10 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

int		ft_valid_char(char c, int base);
int		ft_char_value(char c);
int		ft_atoi_base(const char *nptr, int base);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
#endif
