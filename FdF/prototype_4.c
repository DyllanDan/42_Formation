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

t_list *new_list(float x, float y)
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

void populate_line(t_list *line, float x, float y)
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
		node->x_next = new_point(x + (i * 60 * 0.8 ), y + (i * 60 * 0.6));
		node = node->x_next;
	}
}


void	new_lines(t_list *list, float x, float y)
{
	int		j;
	int		k;

	j = 10;
	k = y;
	while (j-- >= 0)
	{
		populate_line(list, x, k);
		k += (40 * 0.7);
		list->nxt_line = new_list(x, k);
		list = list->nxt_line;
	}
}

void put_x_lines(void *mlx, void *win, t_list *vertical)
{
	int	i;

	i = 0;
	while (vertical != NULL)
	{
		while (vertical->line)
		{
			mlx_pixel_put(mlx, win, vertical->line->x, vertical->line->y, 0xFFFFFF);
			while (vertical->line->x_next != NULL && vertical->line->x + i < vertical->line->x_next->x)
			{
				mlx_pixel_put(mlx, win, vertical->line->x + i, vertical->line->y, 0xFFFFFF);
				i += 1;
			}
			i = 0;
			vertical->line = vertical->line->x_next;
			//printf("a");
		}
		i = 0;
		vertical = vertical->nxt_line;
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

	x = 40;
	y = 40;
	i = 0;
	j = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 640, "Prototype");
	vertical = new_list(x, y);
	new_lines(vertical, x, y);
	put_x_lines(mlx, win, vertical);
	// while (vertical->nxt_line->nxt_line != NULL)
	// {
	// 	while((vertical->nxt_line) && (vertical->y + i) < vertical->nxt_line->y)
	// 	{
	// 		while (j <= 10)
	// 		{
	// 			mlx_pixel_put(mlx, win, vertical->x +(40 * j), vertical->y + i, 0x00BFFF);
	// 			j++;
	// 		}
	// 		i++;
	// 		j=0;
	// 	}
	// 	i = 0;
	// 	vertical = vertical->nxt_line;
	// }
	//mlx_mouse_hook(win, mouse_clicked, (void *)0);
	mlx_loop(mlx);
	return (0);
}

