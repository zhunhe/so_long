/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:49:47 by juhur             #+#    #+#             */
/*   Updated: 2022/02/04 14:45:54 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	check_extension(t_so_long sl)
{
	size_t	len;

	len = ft_strlen(sl.file_name);
	if (len < 5)
		print_error_and_exit(NULL, ERROR_EXTENSION);
	if (ft_strcmp(sl.file_name + len - 4, ".ber") != 0)
		print_error_and_exit(NULL, ERROR_EXTENSION);
}

void	check_wall(t_so_long *sl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sl->height)
	{
		j = -1;
		while (++j < sl->width)
			if (i == 0 || i != sl->height - 1 || j == 0 || j == sl->width - 1)
				if (sl->board[i][j] != WALL)
					print_error_and_exit(sl, ERROR_WALL);
	}
}
