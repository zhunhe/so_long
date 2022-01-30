/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:49:47 by juhur             #+#    #+#             */
/*   Updated: 2022/01/30 16:49:48 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	check_extension(char *file_name)
{
	char	*extension;

	extension = ft_strchr(file_name, '.');
	if (extension == NULL)
		return (error_extension);
	if (ft_strcmp(extension, ".ber") != 0)
		return (error_extension);
	return (ok);
}

int	check_error(char *file_name)
{
	int	errno;

	errno = check_extension(file_name);
	return (errno);
}
