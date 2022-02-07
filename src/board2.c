/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:58 by juhur             #+#    #+#             */
/*   Updated: 2022/02/07 17:45:39 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "so_long.h"

void	set_board_data(t_so_long *sl, const char c)
{
	if (c == PLAYER)
		sl->player_cnt++;
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
	while (++i < sl->height)
	{
		j = -1;
		while (++j < sl->width)
			write(1, &sl->board[i][j], 1);
		write(1, "\n", 1);
	}
}
