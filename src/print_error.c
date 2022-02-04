/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:02:31 by juhur             #+#    #+#             */
/*   Updated: 2022/02/03 20:52:45 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"
#include "libft.h"

void	print_error_and_exit(t_so_long *sl, char *s)
{
	free_struct(sl);
	write(1, s, ft_strlen(s));
	exit(2);
}
