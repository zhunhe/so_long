/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:56:24 by juhur             #+#    #+#             */
/*   Updated: 2022/02/08 16:22:11 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "mlx.h"

void	so_long(char *file_name)
{
	t_so_long	sl;

	init_struct(&sl, file_name);
	check_extension(sl);
	set_board(&sl);
	print_board(&sl);
	sl.mlx.p = mlx_init();
	sl.mlx.w = mlx_new_window(sl.mlx.p, sl.h * LEN, sl.w * LEN, "juhur");
	mlx_key_hook(sl.mlx.w, key_hook, &sl);
	mlx_loop(sl.mlx.p);
}

void	free_struct(t_so_long *sl)
{
	int	idx;

	if (sl->board == NULL)
		return ;
	idx = 0;
	while (idx < sl->h)
	{
		if (sl->board[idx])
			free(sl->board[idx]);
		sl->board[idx++] = NULL;
	}
	if (sl->board)
	{
		free(sl->board);
		sl->board = NULL;
	}
}
