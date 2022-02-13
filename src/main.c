/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:38:33 by juhur             #+#    #+#             */
/*   Updated: 2022/02/13 09:28:10 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_so_long	g;

	if (argc == 2)
	{
		init_struct(&g, argv[1]);
		check_extension(&g);
		set_board(&g);
		print_board(&g);
		init_mlx(&g);
		print_init_image(&g);
		mlx_hook(g.win, DESTROY_NOTIFY, 0, mouse_hook, &g);
		mlx_key_hook(g.win, key_hook, &g);
		mlx_loop(g.mlx);
	}
	return (0);
}
