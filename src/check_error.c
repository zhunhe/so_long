/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:49:47 by juhur             #+#    #+#             */
/*   Updated: 2022/02/13 09:43:07 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	check_extension(t_so_long *g)
{
	size_t	len;

	len = ft_strlen(g->file_name);
	if (len < 5)
		exit_so_long(g, ERROR_EXTENSION);
	if (ft_strcmp(g->file_name + len - 4, ".ber") != 0)
		exit_so_long(g, ERROR_EXTENSION);
}

void	check_wall(t_so_long *g)
{
	int	i;

	i = -1;
	while (++i < g->board_h)
		if (g->board[i][0] != WALL || g->board[i][g->board_w - 1] != WALL)
			exit_so_long(g, ERROR_WALL);
	i = -1;
	while (++i < g->board_w)
		if (g->board[0][i] != WALL || g->board[g->board_h - 1][i] != WALL)
			exit_so_long(g, ERROR_WALL);
}

void	check_invalid_char(t_so_long *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->board_h)
	{
		j = -1;
		while (++j < g->board_w)
		{
			if (g->board[i][j] == EMPTY)
				continue ;
			if (g->board[i][j] == WALL)
				continue ;
			if (g->board[i][j] == COLLECTIBLE)
				continue ;
			if (g->board[i][j] == EXIT)
				continue ;
			if (g->board[i][j] == PLAYER)
				continue ;
			exit_so_long(g, ERROR_INVALID_CHAR);
		}
	}
}

void	check_board_data(t_so_long *g)
{
	if (g->player.count == 0)
		exit_so_long(g, ERROR_NO_PLAYER);
	if (g->exit.count == 0)
		exit_so_long(g, ERROR_NO_EXIT);
	if (g->collectible.count == 0)
		exit_so_long(g, ERROR_NO_COLLECTIBLE);
}
