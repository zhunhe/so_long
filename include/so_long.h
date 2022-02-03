/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:06:52 by juhur             #+#    #+#             */
/*   Updated: 2022/02/03 20:00:56 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERROR_EXTENSION	"Error! file extension is not .ber"

/*
** so_long.c
*/
void	so_long(char *file_name);
/*
** check_error.c
*/
void	check_error(char *file_name);
/*
** print_error.c
*/
void print_error_and_exit(char *s);
# define BUFFER_SIZE	1000000
#endif