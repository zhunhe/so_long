/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:19:15 by juhur             #+#    #+#             */
/*   Updated: 2022/02/13 08:11:29 by juhur            ###   ########.fr       */
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
		exit_so_long(NULL, ERROR_FD);
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			close(fd);
			exit_so_long(NULL, ERROR_FD);
		}
		if (len == 0)
			break ;
		size += len;
	}
	close(fd);
	return (size);
}

static void	set_string(t_so_long *g)
{
	int		fd;
	int		len;
	char	buffer[BUFFER_SIZE];

	fd = open(g->file_name, O_RDONLY);
	if (fd == -1)
		exit_so_long(NULL, ERROR_FD);
	*g->s = '\0';
	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			exit_so_long(NULL, ERROR_FD);
		if (len == 0)
			break ;
		buffer[len] = '\0';
		ft_strlcat(g->s, buffer, len + 1);
	}
	close(fd);
}

static void	set_board_height_width(t_so_long *g)
{
	int	idx;
	int	len;

	idx = -1;
	while (++idx < g->s_size)
		if (g->s[idx] != '\n' && (idx == 0 || g->s[idx - 1] == '\n'))
			g->board_h++;
	idx = -1;
	while (++idx < g->s_size)
	{
		len = 0;
		while (idx < g->s_size && g->s[idx] != '\n')
		{
			idx++;
			len++;
		}
		if (g->board_w == 0)
			g->board_w = len;
		else if (g->board_w != len)
			exit_so_long(g, ERROR_RECTANGLE);
	}
}

static void	set_board_main(t_so_long *g)
{
	int	i;
	int	j;
	int	idx;

	g->board = (char **)malloc(sizeof(char *) * (g->board_h + 1));
	if (g->board == NULL)
		exit_so_long(g, ERROR_MALLOC);
	idx = 0;
	i = -1;
	while (++i < g->board_h)
	{
		g->board[i] = (char *)malloc(sizeof(char) * (g->board_w + 1));
		if (g->board[i] == NULL)
			exit_so_long(g, ERROR_MALLOC);
		j = -1;
		while (++j < g->board_w)
		{
			while (g->s[idx] == '\n')
				idx++;
			g->board[i][j] = g->s[idx++];
			set_board_data(g, g->board[i][j], i, j);
		}
	}
}

void	set_board(t_so_long *g)
{
	g->s_size = get_file_size(g->file_name);
	if (g->s_size < 17)
		exit_so_long(g, ERROR_MAP_SIZE);
	g->s = (char *)malloc(sizeof(char) * (g->s_size + 1));
	if (g->s == NULL)
		exit_so_long(g, ERROR_MALLOC);
	set_string(g);
	set_board_height_width(g);
	set_board_main(g);
	check_board_data(g);
	check_wall(g);
	check_invalid_char(g);
}
