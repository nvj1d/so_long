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

int	main(int ac, char **av)
{
	t_map	*map;
	(void)av;
	if (ac < 2)
		ft_error(0, NULL);
	map = (t_map *)malloc(sizeof(t_map));
	ft_init(map);
	ft_check_map(map, av[1]);
	// map->mlx = mlx_init();
	// if (!map->mlx)
	// 	ft_error(1, map);
	// map->mlx_win = mlx_new_window(map->mlx, map->height * 50, \
	// 	map->width * 50, "So_long!");
	//ft_print_full(map);
}
