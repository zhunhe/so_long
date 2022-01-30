/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:38:33 by juhur             #+#    #+#             */
/*   Updated: 2022/01/29 20:38:34 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "so_long.h"
#include "libft.h"

static void	print_errormsg(int errno)
{
	if (errno == error_extension)
		write(2, ERROR_EXTENSION, ft_strlen(ERROR_EXTENSION));
}

int	main(int argc, char **argv)
{
	int		errno;

	if (argc == 2)
	{
		errno = so_long(argv[1]);
		if (errno)
			print_errormsg(errno);
	}
	return (0);
}
