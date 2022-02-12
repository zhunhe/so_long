/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:27:06 by juhur             #+#    #+#             */
/*   Updated: 2022/02/12 13:37:34 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "so_long.h"
#include "mlx.h"

static void	set_image(void *mlx, char *path, t_img *image)
{
	image->img = mlx_xpm_file_to_image(mlx, path, &image->w, &image->h);
}

void	init_mlx(t_so_long *g)
{
	g->mlx = mlx_init();
	set_image(g->mlx, PATH_BACKGROUND, &g->bg);
	set_image(g->mlx, PATH_PLAYER, &g->player);
	set_image(g->mlx, PATH_WALL, &g->wall);
	set_image(g->mlx, PATH_EXIT, &g->exit);
	set_image(g->mlx, PATH_COLLECTIBLE, &g->collectible);
	g->win_w = g->board_w * g->bg.w;
	g->win_h = g->board_h * g->bg.h;
}

void	init_struct(t_so_long *g, char *file_name)
{
	g->file_name = file_name;
	g->board = NULL;
	g->s = NULL;
	g->board_h = 0;
	g->board_w = 0;
	g->collectible_cnt = 0;
	g->exit_cnt = 0;
	g->player_cnt = 0;
	g->move_cnt = 0;
	g->y = -1;
	g->x = -1;
	g->mlx = NULL;
	g->win = NULL;
}
