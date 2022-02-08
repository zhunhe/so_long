/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:06:52 by juhur             #+#    #+#             */
/*   Updated: 2022/02/08 11:04:46 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_mlx
{
	void	*p;
	void	*w;
}	t_mlx;

typedef struct s_so_long
{
	char		*file_name;
	char		**board;
	char		*s;
	int			height;
	int			width;
	int			collectible_cnt;
	int			exit_cnt;
	int			player_cnt;
	t_mlx		mlx;
}	t_so_long;

# define EMPTY			'0'
# define WALL			'1'
# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'

# define ERROR_EXTENSION		"Error! file extension is not .ber"
# define ERROR_FD				"Error! invalid file descriptor"
# define ERROR_MAP_SIZE			"Error! invalid map size"
# define ERROR_MALLOC			"Error! insufficient memory"
# define ERROR_WALL				"Error! outside board is not wall"
# define ERROR_RECTANGLE		"Error! board is not rectangle"
# define ERROR_INVALID_CHAR		"Error! there is invalid character in board"
# define ERROR_NO_PLAYER		"Error! there is no player on the board"
# define ERROR_NO_EXIT			"Error! there is no exit on the board"
# define ERROR_NO_COLLECTIBLE	"Error! there is no collectible on the board"

/*
** so_long.c
*/
void	so_long(char *file_name);
void	free_struct(t_so_long *sl);
/*
** init.c
*/
void	init_struct(t_so_long *sl, char *file_name);
/*
** check_error.c
*/
void	check_extension(t_so_long sl);
void	check_wall(t_so_long *sl);
void	check_invalid_char(t_so_long *sl);
void	check_board_data(t_so_long *sl);
/*
** print_error.c
*/
void	print_error_and_exit(t_so_long *sl, char *s);
/*
** board.c
*/
void	set_board(t_so_long *sl);
/*
** board2.c
*/
void	set_board_data(t_so_long *sl, const char c);
void	print_board(t_so_long *sl);
# define BUFFER_SIZE	1000000
#endif