/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:02:31 by juhur             #+#    #+#             */
/*   Updated: 2022/02/08 15:37:10 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"
#include "libft.h"

void	sl_exit(t_so_long *sl, char *s)
{
	if (sl != NULL)
		free_struct(sl);
	if (s != NULL)
	{
		printf("%s\n", s);
		exit(2);
	}
	else
		exit(0);
}
