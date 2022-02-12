/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:56:24 by juhur             #+#    #+#             */
/*   Updated: 2022/02/12 13:43:13 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "mlx.h"

void	so_long(char *file_name)
{
	t_so_long	g;

	init_struct(&g, file_name);
	check_extension(&g);
	set_board(&g);
	print_board(&g);
	init_mlx(&g);
	print_init_image(&g);
	mlx_hook(g.win, 17, 0, mouse_hook, &g);
	mlx_key_hook(g.win, key_hook, &g);
	mlx_loop(g.mlx);
}

void	free_struct(t_so_long *g)
{
	int	idx;

	if (g->board == NULL)
		return ;
	idx = 0;
	while (idx < g->board_h)
	{
		if (g->board[idx])
			free(g->board[idx]);
		g->board[idx++] = NULL;
	}
	if (g->board)
	{
		free(g->board);
		g->board = NULL;
	}
}

void	destroy_image(t_so_long *g)
{
	if (g->bg.img != NULL)
		mlx_destroy_image(g->mlx, g->bg.img);
	if (g->player.img != NULL)
		mlx_destroy_image(g->mlx, g->player.img);
	if (g->collectible.img != NULL)
		mlx_destroy_image(g->mlx, g->collectible.img);
	if (g->exit.img != NULL)
		mlx_destroy_image(g->mlx, g->exit.img);
	if (g->wall.img != NULL)
		mlx_destroy_image(g->mlx, g->wall.img);
	if (g->win != NULL)
		mlx_destroy_window(g->mlx, g->win);
}
