/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:06:52 by juhur             #+#    #+#             */
/*   Updated: 2022/01/30 15:06:53 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

enum e_error
{
	ok = 0,
	error_extension,
	error_max
};

# define ERROR_EXTENSION	"Error! file extension is not .ber"

/*
** so_long.c
*/
int		so_long(char *file_name);
/*
** check_error.c
*/
int		check_error(char *file_name);

#endif