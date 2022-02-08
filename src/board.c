/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:19:15 by juhur             #+#    #+#             */
/*   Updated: 2022/02/08 15:35:25 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"
#include "libft.h"

static int	get_file_size(char *file_name)
{
	int		fd;
	int		size;
	int		len;
	char	buffer[BUFFER_SIZE];

	size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		sl_exit(NULL, ERROR_FD);
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			close(fd);
			sl_exit(NULL, ERROR_FD);
		}
		if (len == 0)
			break ;
		size += len;
	}
	close(fd);
	return (size);
}

static void	set_string(t_so_long *sl)
{
	int		fd;
	int		len;
	char	buffer[BUFFER_SIZE];

	fd = open(sl->file_name, O_RDONLY);
	if (fd == -1)
		sl_exit(NULL, ERROR_FD);
	*sl->s = '\0';
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			sl_exit(NULL, ERROR_FD);
		if (len == 0)
			break ;
		buffer[len] = '\0';
		ft_strlcat(sl->s, buffer, len + 1);
	}
	close(fd);
}

static void	set_board_height_width(t_so_long *sl)
{
	int	idx;
	int	len;

	idx = 0;
	while (sl->s[idx] != '\0')
	{
		if (idx == 0 || sl->s[idx - 1] == '\n')
			sl->h++;
		idx++;
	}
	idx = 0;
	while (sl->s[idx] != '\0')
	{
		len = 0;
		while (sl->s[idx] != '\0' && sl->s[idx] != '\n')
		{
			idx++;
			len++;
		}
		idx++;
		if (sl->w == 0)
			sl->w = len;
		else if (sl->w != len)
			sl_exit(sl, ERROR_RECTANGLE);
	}
}

static void	set_board_main(t_so_long *sl)
{
	int	i;
	int	j;
	int	idx;

	sl->board = (char **)malloc(sizeof(char *) * (sl->h + 1));
	if (sl->board == NULL)
		sl_exit(sl, ERROR_MALLOC);
	idx = 0;
	i = -1;
	while (++i < sl->h)
	{
		sl->board[i] = (char *)malloc(sizeof(char) * (sl->w + 1));
		if (sl->board[i] == NULL)
			sl_exit(sl, ERROR_MALLOC);
		j = -1;
		while (++j < sl->w)
		{
			sl->board[i][j] = sl->s[idx++];
			set_board_data(sl, sl->board[i][j], i, j);
			if (sl->s[idx] == '\n')
				idx++;
		}
	}
}

void	set_board(t_so_long *sl)
{
	int		size;

	size = get_file_size(sl->file_name);
	if (size < 14)
		sl_exit(sl, ERROR_MAP_SIZE);
	sl->s = (char *)malloc(sizeof(char) * (size + 1));
	if (sl->s == NULL)
		sl_exit(sl, ERROR_MALLOC);
	set_string(sl);
	set_board_height_width(sl);
	set_board_main(sl);
	check_board_data(sl);
	check_wall(sl);
	check_invalid_char(sl);
}
