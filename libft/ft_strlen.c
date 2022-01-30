/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:18:29 by juhur             #+#    #+#             */
/*   Updated: 2022/01/30 14:51:51 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strlen -- find length of string <string.h>
*/
size_t	ft_strlen(const char *s)
{
	const char	*end;

	end = s;
	while (*end != '\0')
		++end;
	return (end - s);
}
