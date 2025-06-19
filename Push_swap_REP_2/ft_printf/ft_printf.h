/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:54:40 by dydaniel          #+#    #+#             */
/*   Updated: 2024/11/09 14:49:45 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_itoa_long(long n);
void	ft_putstr(char *str, int *count);
void	ft_putnums(long n, int *count, char no_sign);
void	ft_puthex(unsigned long num, int *count, char c);
void	ft_putchar(char c, int *count);
int		ft_toupper(int c);
int		ft_printf(const char *argument, ...);

#endif
