/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:11:08 by dydaniel          #+#    #+#             */
/*   Updated: 2025/04/05 16:29:49 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*nxt;
}	t_stack;

int		ft_isdigit(int c);
int		ft_valid_char(char c, int base);
int		ft_char_value(char c);
long	ft_atoi_base(const char *nptr, int base);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		size_stack(t_stack *a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
t_stack	*create_stack(void);
void	populate_stack(char **argv, t_stack *a);
int		size_stack(t_stack *a);
int		is_sorted(t_stack *a);
void	sort_maker(t_stack **a, t_stack **b, int size);
void	small_sort(t_stack **a, t_stack **b, int size);
int		f_is_lower(t_stack *a, int size);
void	sort_5(t_stack **a, t_stack **b, int size);
void	sort_4(t_stack **a, t_stack **b, int size);
void	sort_3(t_stack **a);
void	sort_2(t_stack **a);
void	free_stack(t_stack *a);
int		f_is_higher(t_stack *a, int size);
int		check_error(char **splitted);
int		check_rep(char **splitted);
int		check_args(char **split);
int		check_space(char **str);
void	check_sign(char **str1, char **str2);
void	big_sort(t_stack **a, t_stack **b, int size);
void	convert_index(t_stack **a);
void	free_split(char **splitted);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
size_t	ft_count_words(const char *s, char c);
char	**ft_move_w(char **list, char const *s, char c);
char	*ft_get_str(char const *s, int len);
size_t	ft_lenword(const char *str, char c);
size_t	ft_strlen(const char *s);
#endif
