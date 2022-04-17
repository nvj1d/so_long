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

	if (argc == 2)
	{
		map.map_array = ft_map_init(argv[1], &map);
		if (!map.map_array)
			return (0);
		ft_map_check(&map);
		ft_init_game(&game, &map, &img);
		h = map.height * 50;
		w = map.width * 50;
		game.win_ptr = mlx_new_window(game.mlx_ptr, w, h, "let's dance!" );
		ft_drawer_init(&game, &img);
		ft_game_drawer(&map, &game, &img);
		// mlx_hook();
		// mlx_loop();
	}
	else
		ft_printf("the syntax is : ./so_long map\n");
	return (0);
}
