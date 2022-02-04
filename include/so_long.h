/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:06:52 by juhur             #+#    #+#             */
/*   Updated: 2022/02/04 15:56:37 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_so_long
{
	char	*file_name;
	char	**board;
	char	*s;
	int		height;
	int		width;
}	t_so_long;

# define EMPTY			'0'
# define WALL			'1'
# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'

# define ERROR_EXTENSION	"Error! file extension is not .ber"
# define ERROR_FD			"Error! invalid file descriptor"
# define ERROR_MAP_SIZE		"Error! invalid map size"
# define ERROR_MALLOC		"Error! insufficient memory"
# define ERROR_WALL			"Error! outside board is not wall"
# define ERROR_RECTANGLE	"Error! board is not rectangle"
# define ERROR_INVALID_CHAR	"Error! there is invalid character in board"

/*
** so_long.c
*/
void	so_long(char *file_name);
void	free_struct(t_so_long *sl);
/*
** check_error.c
*/
void	check_extension(t_so_long sl);
void	check_wall(t_so_long *sl);
void	check_invalid_char(t_so_long *sl);
/*
** print_error.c
*/
void	print_error_and_exit(t_so_long *sl, char *s);
/*
** board.c
*/
void	set_board(t_so_long *sl);
# define BUFFER_SIZE	1000000
#endif