/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:58 by juhur             #+#    #+#             */
/*   Updated: 2022/02/07 15:18:18 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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