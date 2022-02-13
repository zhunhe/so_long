/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:06:52 by juhur             #+#    #+#             */
/*   Updated: 2022/02/13 09:34:23 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_img
{
	void	*img;
	char	*path;
	int		h;
	int		w;
}	t_img;

typedef struct s_so_long
{
	char		*file_name;
	char		**board;
	char		*s;
	int			s_size;
	int			board_h;
	int			board_w;
	int			collectible_cnt;
	int			exit_cnt;
	int			player_cnt;
	int			move_cnt;
	void		*mlx;
	void		*win;
	int			y;
	int			x;
	int			win_h;
	int			win_w;
	t_img		bg;
	t_img		player;
	t_img		wall;
	t_img		exit;
	t_img		collectible;
}	t_so_long;

# define EMPTY			'0'
# define WALL			'1'
# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_ESC		53

# define DESTROY_NOTIFY	17

# define MAX_MOVE_COUNT	100

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
# define MOVE_COUNT_OVER		"Game Over!"

# define PATH_BACKGROUND		"./image/background.xpm"
# define PATH_PLAYER			"./image/player.xpm"
# define PATH_WALL				"./image/wall.xpm"
# define PATH_EXIT				"./image/exit.xpm"
# define PATH_COLLECTIBLE		"./image/collectible.xpm"

/*
** exit.c
*/
void	exit_so_long(t_so_long *g, char *s);
/*
** init.c
*/
void	init_struct(t_so_long *g, char *file_name);
void	init_mlx(t_so_long *g);
/*
** check_error.c
*/
void	check_extension(t_so_long *g);
void	check_wall(t_so_long *g);
void	check_invalid_char(t_so_long *g);
void	check_board_data(t_so_long *g);
/*
** print.c
*/
void	print_init_image(t_so_long *g);
void	print_player(t_so_long *g, int b_x, int b_y);
/*
** board.c
*/
void	set_board(t_so_long *g);
/*
** board2.c
*/
void	set_board_data(t_so_long *g, const char c, int y, int x);
void	print_board(t_so_long *g);
/*
** hook.c
*/
int		key_hook(int key, t_so_long *g);
int		mouse_hook(t_so_long *g);
# define BUFFER_SIZE	1000000
#endif