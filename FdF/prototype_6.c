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
//10 linhas
typedef struct  s_point
{
	int		x;
	int		y;
	struct s_point	 *x_next;
}	t_point;


t_point *new_point(float x, float y)
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
	struct	s_point *line;
}	t_list;

t_list *new_list(int x, int y)
{
	t_list	*list;

	list = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->x = x;
	list->y = y;
	list->nxt_line = NULL;
	list->line = NULL;

	return(list);
}

void populate_line(t_list *line, int x, int y)
{
	t_point	*node;
	int	i;
	int j;

	i = 0;
	j = 0;
	node = new_point(x, y);
	line->line = node;
	while (++i <= 10)
	{
		node->x_next = new_point(x + (i * 30), y + (i * 30));
		node = node->x_next;
	}
}


void	new_lines(t_list *list, int x, int y)
{
	int		j;
	int		k;
	int		l;

	j = 10;
	k = y;
	l = 0;
	while (j-- >= 0)
	{
		populate_line(list, x - (30 * l), k);
		k += (40);
		list->nxt_line = new_list(x, k);
		list = list->nxt_line;
		l++;
	}
}

void put_dots(void *mlx, void *win, t_list *vertical)
{
	t_point	*node;

	while (vertical)
	{
		node = vertical->line;
		while (node)
		{
			mlx_pixel_put(mlx, win, node->x, node->y, 0xCCCC00);
			node = node->x_next;
		}
		vertical = vertical->nxt_line;
	}
}

void put_x_line(void *mlx, void *win, t_list *vertical)
{
	int	dx;
	int	dy;
	int D;
	int x;
	int y;
	t_list	*line;
	t_point	*node;

	line = vertical;
	while (line->nxt_line)
	{
		node = line->line;
		while (node->x_next)
		{
			x = node->x;
			y = node->y;
			dx = node->x_next->x - node->x;
			dy = node->x_next->y - node->y;
			D = (2 * dx) - dy;
			while(y < node->x_next->y )
			{
				mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
				if(D > 0)
				{
					x++;
					D = D + (2 *(dx - dy));
				}
				else
					D = D + 2 * dx;
				y++;
			}
			node = node->x_next;
		}
		line = line->nxt_line;
	}
}

void put_y_line(void *mlx, void *win, t_list *vertical)
{
	int	dx;
	int	dy;
	int D;
	int x;
	int y;
	int	j;
	t_list *aux;

	aux = vertical;
	x = aux->x;
	y = aux->y;
	while(aux->nxt_line)
	{
		while(y < aux->nxt_line->y)
		{
			dx = aux->nxt_line->x - aux->x;
			dy = aux->nxt_line->y - aux->y;
			D = (2 * dx) - dy;
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			if(D < 0)
			{
				x--;
				D = D + (2 *(dx - dy));
			}
			else
				D = D + 2 * dx;
			y++;
		}
		aux = aux->nxt_line;
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	float		x;
	float		y;
	t_list	*vertical;
	int	i;
	int j;

	x = 400;
	y = 150;
	i = 0;
	j = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 900, 900, "Prototype");
	vertical = new_list(x, y);
	new_lines(vertical, x, y);	
	put_dots(mlx, win, vertical);
	put_x_line(mlx, win, vertical);
	// if (vertical->nxt_line)
	// 	mlx_pixel_put(mlx, win, 10, 10, 0xFFF00F);
	put_y_line(mlx, win, vertical);
	mlx_loop(mlx);
	return (0);
}

