/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:56:24 by juhur             #+#    #+#             */
/*   Updated: 2022/02/07 16:26:21 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"

static void	init_struct(t_so_long *sl, char *file_name)
{
	sl->file_name = file_name;
	sl->board = NULL;
	sl->s = NULL;
	sl->height = 0;
	sl->width = 0;
	sl->collectible_cnt = 0;
	sl->exit_cnt = 0;
	sl->player_cnt = 0;
}

void	so_long(char *file_name)
{
	t_so_long	sl;

	init_struct(&sl, file_name);
	check_extension(sl);
	set_board(&sl);
}

void	free_struct(t_so_long *sl)
{
	size_t	idx;

	if (sl->board == NULL)
		return ;
	idx = 0;
	while (sl->board[idx])
	{
		free(sl->board[idx]);
		sl->board[idx++] = NULL;
	}
	if (sl->board)
	{
		free(sl->board);
		sl->board = NULL;
	}
}
