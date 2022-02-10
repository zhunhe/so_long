/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:02:31 by juhur             #+#    #+#             */
/*   Updated: 2022/02/10 20:54:00 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"
#include "libft.h"
#include "mlx.h"

void	sl_exit(t_so_long *g, char *s)
{
	destroy_image(g);
	if (g != NULL)
		free_struct(g);
	if (s != NULL)
		printf("%s\n", s);
	exit(0);
}

static void	print_image(t_so_long *g, void *img, int x, int y)
{
	if (img == g->player.img)
		mlx_put_image_to_window(g->mlx, g->win, img, x - 5, y - 5);
	else
		mlx_put_image_to_window(g->mlx, g->win, img, x, y);
}

void	print_init_image(t_so_long *g)
{
	int		i;
	int		j;

	g->win = mlx_new_window(g->mlx, g->win_w, g->win_h, "juhur");
	i = -1;
	while (++i < g->board_w)
	{
		j = -1;
		while (++j < g->board_h)
		{
			if (g->board[j][i] == WALL)
				print_image(g, g->wall.img, i * g->bg.w, j * g->bg.h);
			else
				print_image(g, g->bg.img, i * g->bg.w, j * g->bg.h);
			if (g->board[j][i] == COLLECTIBLE)
				print_image(g, g->collectible.img, i * g->bg.w, j * g->bg.h);
			if (g->board[j][i] == EXIT)
				print_image(g, g->exit.img, i * g->bg.w, j * g->bg.h);
		}
	}
	print_player(g, g->x, g->y);
}

void	print_player(t_so_long *g, int b_x, int b_y)
{
	print_image(g, g->bg.img, b_x * g->bg.w, b_y * g->bg.h);
	print_image(g, g->bg.img, g->x * g->bg.w, g->y * g->bg.h);
	print_image(g, g->player.img, g->x * g->bg.w, g->y * g->bg.h);
}
