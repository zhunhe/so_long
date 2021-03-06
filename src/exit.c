/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:56:24 by juhur             #+#    #+#             */
/*   Updated: 2022/02/13 09:34:13 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"
#include "mlx.h"

static void	free_struct(t_so_long *g)
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

static void	destroy_image(t_so_long *g)
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

void	exit_so_long(t_so_long *g, char *s)
{
	if (g->s != NULL)
		free(g->s);
	if (g->board != NULL)
		free_struct(g);
	if (g->win != NULL)
		destroy_image(g);
	if (s != NULL)
		printf("%s\n", s);
	exit(0);
}
