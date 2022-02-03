/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:49:47 by juhur             #+#    #+#             */
/*   Updated: 2022/02/03 15:41:22 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	check_extension(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 5)
		return (error_extension);
	if (ft_strcmp(file_name + len - 4, ".ber") != 0)
		return (error_extension);
	return (ok);
}

int	check_error(char *file_name)
{
	int	errno;

	errno = check_extension(file_name);
	return (errno);
}
