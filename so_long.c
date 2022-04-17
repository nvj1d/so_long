/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:27:07 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/07 20:27:07 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;
	t_img	img;
	int		h;
	int		w;
	if (argc != 2)
		ft_printf("the syntax is : ./so_long map\n");
	game.map = ft_map_init(argv[1], &map);
	ft_init(map);
	ft_check_map(map, av[1]);
	// map->mlx = mlx_init();
	// if (!map->mlx)
	// 	ft_error(1, map);
	// map->mlx_win = mlx_new_window(map->mlx, map->height * 50, \
	// 	map->width * 50, "So_long!");
	//ft_print_full(map);
	mlx_key_hook(map->mlx_win,ft_move,map);
	mlx_loop(map->mlx);
}
