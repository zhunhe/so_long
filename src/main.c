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
#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		// for make test
		write(1, argv[1], ft_strlen(argv[1]));
	}
	return (0);
}
