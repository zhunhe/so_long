/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:58 by juhur             #+#    #+#             */
/*   Updated: 2022/02/08 13:36:31 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "so_long.h"

void	set_board_data(t_so_long *sl, const char c, int y, int x)
{
	if (c == PLAYER)
	{
		sl->player_cnt++;
		sl->player.y = y;
		sl->player.x = x;
	}
	else if (c == COLLECTIBLE)
		sl->collectible_cnt++;
	else if (c == EXIT)
		sl->exit_cnt++;
}

void	print_board(t_so_long *sl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sl->h)
	{
		j = -1;
		while (++j < sl->w)
			write(1, &sl->board[i][j], 1);
		write(1, "\n", 1);
	}
}
