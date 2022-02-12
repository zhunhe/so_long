/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:33:25 by juhur             #+#    #+#             */
/*   Updated: 2022/02/13 08:11:29 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "so_long.h"

static void	move(t_so_long *g, int dir)
{
	const int	dy[4] = {0, 1, 0, -1};
	const int	dx[4] = {-1, 0, 1, 0};
	const int	ny = g->y + dy[dir];
	const int	nx = g->x + dx[dir];

	if (ny < 0 || nx < 0 || ny >= g->board_h || nx >= g->board_w)
		return ;
	if (g->board[ny][nx] == WALL
	|| (g->board[ny][nx] == EXIT && g->collectible_cnt != 0))
		return ;
	if (g->board[ny][nx] == EXIT)
		exit_so_long(g, NULL);
	if (g->board[ny][nx] == COLLECTIBLE)
		g->collectible_cnt--;
	g->move_cnt++;
	if (g->move_cnt == MAX_MOVE_COUNT)
		exit_so_long(g, MOVE_COUNT_OVER);
	printf("move count [%d/%d]\n", g->move_cnt, MAX_MOVE_COUNT);
	g->board[g->y][g->x] = EMPTY;
	g->board[ny][nx] = PLAYER;
	g->y = ny;
	g->x = nx;
	print_player(g, nx - dx[dir], ny - dy[dir]);
}

int	key_hook(int key, t_so_long *g)
{
	if (key == KEY_ESC)
		exit_so_long(g, NULL);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move(g, key % 10);
	return (0);
}

int	mouse_hook(t_so_long *g)
{
	exit_so_long(g, NULL);
	return (0);
}
