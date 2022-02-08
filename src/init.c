/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:27:06 by juhur             #+#    #+#             */
/*   Updated: 2022/02/08 13:53:03 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "so_long.h"

static void	init_mlx(t_so_long *sl)
{
	sl->mlx.p = NULL;
	sl->mlx.w = NULL;
}

static void	init_player(t_so_long *sl)
{
	sl->player.y = -1;
	sl->player.x = -1;
}

void	init_struct(t_so_long *sl, char *file_name)
{
	sl->file_name = file_name;
	sl->board = NULL;
	sl->s = NULL;
	sl->h = 0;
	sl->w = 0;
	sl->collectible_cnt = 0;
	sl->exit_cnt = 0;
	sl->player_cnt = 0;
	init_mlx(sl);
	init_player(sl);
}
