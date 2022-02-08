/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:33:25 by juhur             #+#    #+#             */
/*   Updated: 2022/02/08 14:04:23 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"

static void	move(t_so_long *sl, int dir)
{
	const int	dy[4] = {0, 1, 0, -1};
	const int	dx[4] = {-1, 0, 1, 0};
	const int	ny = sl->player.y + dy[dir];
	const int	nx = sl->player.x + dx[dir];

	if (ny < 0 || nx < 0 || ny >= sl->h || nx >= sl->w)
		return ;
	if (sl->board[ny][nx] == WALL
	|| (sl->board[ny][nx] == EXIT && sl->collectible_cnt != 0))
		return ;
	if (sl->board[ny][nx] == EXIT)
		exit(0);
	if (sl->board[ny][nx] == COLLECTIBLE)
		sl->collectible_cnt--;
	sl->board[sl->player.y][sl->player.x] = EMPTY;
	sl->board[ny][nx] = PLAYER;
	sl->player.y = ny;
	sl->player.x = nx;
}

int	key_hook(int keycode, t_so_long *sl)
{
	move(sl, keycode % 10);
	print_board(sl);
	return (0);
}
