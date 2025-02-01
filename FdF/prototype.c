/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:20:46 by dydaniel          #+#    #+#             */
/*   Updated: 2025/01/25 14:12:14 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

//linha 10 pontos
//3 linhas
typedef struct  s_point
{
	int		x;
	int		y;
	struct s_point	 *x_next;
}	t_point;


t_point *new_point(int x, int y)
{
	t_point		*point;

	point = NULL;
	point = (t_point *)malloc(sizeof(t_point));
	if (point == NULL)
		return (0);
	point->x = x;
	point->y = y;
	point->x_next = NULL;
	return (point);
}


typedef struct s_list
{
	int		x;
	int		y;
	struct	s_list	*nxt_line;
	struct	t_point *line;
}	t_list;

t_list *new_list(int x, int y)
{
	t_list	*list;

	list = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (list = NULL)
		return (NULL);
	list->x = x;
	list->y = y;
	list->next_line = NULL;
	list->line = NULL;
}

void populate_line(t_list *line, int x, int y)
{
	t_point	*node;
	int	i;

	i = 0
	node = line->line;
	node = (t_point *)malloc(sizeof(t_point));
	if (node == NULL);
		return (NULL)
	node = new_point(x, y);
	while (++i < 10)
	{
		node->x_next = new_point(20 + (i * 10), 20 + (j*10));
		mlx_pixel_put(mlx, win, aux->x, aux->y, 0xFFFFFF);
		node = node->x_next;
	}
}


int	main(void)
{
	void	*mlx;
	void	*win;
	t_point		*point;
	t_point		*aux;
	t_point		*aux_2;
	int	i;
	int	j;

	i = 0;
	j = 0;
	point = new_point(20, 20);
	aux = point;
	aux_2 = point;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 360, "Prototype");
	while (++i < 20)
	{
		point->x_next = new_point(20 + (i * 10), 20 + (j*10));
		point = point->x_next;
	}
	while (aux)
	{
		mlx_pixel_put(mlx, win, aux->x, aux->y, 0xFFFFFF);
		aux = aux->x_next;
	}
//	mlx_mouse_hook(win, mouse_clicked, (void *)0);
	mlx_loop(mlx);
	return (0);
}

/*
while (i++ < 20)
		mlx_pixel_put(mlx, win, (320), (180 + i), 0xFFFFFF);
	i = 0;
	while (i++ < 20)
		mlx_pixel_put(mlx, win, (320 + i), (200), 0xFFFFFF);
	i = 0;
	while (i++ < 20)
		mlx_pixel_put(mlx, win, (340), (200 - i), 0xFFFFFF);
	i = 0;
	while (i++ < 20)
		mlx_pixel_put(mlx, win, (340 - i), (180), 0xFFFFFF);*/
