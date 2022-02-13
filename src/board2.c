/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:58 by juhur             #+#    #+#             */
/*   Updated: 2022/02/13 09:43:07 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	set_board_data(t_so_long *g, const char c, int y, int x)
{
	if (c == PLAYER)
	{
		g->player.count++;
		g->y = y;
		g->x = x;
	}
	else if (c == COLLECTIBLE)
		g->collectible.count++;
	else if (c == EXIT)
		g->exit.count++;
}

void	print_board(t_so_long *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->board_h)
	{
		j = -1;
		while (++j < g->board_w)
			printf("%c", g->board[i][j]);
		printf("\n");
	}
}
