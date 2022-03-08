/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:23:44 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/07 21:23:44 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

ft_put_image_window(t_map *map,char *imgptr,int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, imgptr, j*75, i*75);
}

ft_xml_xmp_to_img(t_map *map)
{
	char *player;
	char *item;
	char *exit;
	char *wall;
	char *empty;

	player = "./xpm/player.xpm";
	item = "./xpm/item.xpm";
	exit = "./xpm/exit.xpm";
	wall = "./xpm/wall.xpm";
	empty = "./xpm/empty.xpm";
	map->player = mlx_xmp_file_to_image(map->mlx,player,map->font_w,map->font_h);
	map->item = mlx_xmp_file_to_image(map->mlx,item,map->font_w,map->font_h);
	map->exit = mlx_xmp_file_to_image(map->mlx,exit,map->font_w,map->font_h);
	map->empty = mlx_xmp_file_to_image(map->mlx,empty,map->font_w,map->font_h);
	map->wall = mlx_xmp_file_to_image(map->mlx,wall,map->font_w,map->font_h);
}

void ft_print_full(t_map *map)
{
	int i;
	int j;
	
	i = 0;
	ft_xml_xmp_to_img(map);
	while (i < map->height)
	{
		j = 0;
		while (map->map_array[i][j])
		{
			ft_put_image_window(map, map->empty, i, j);
			if (map->map_array[i][j] == '1')
				ft_put_image_window(map, map->wall,i,j);
			if (map->map_array[i][j] == 'E')
				ft_put_image_window(map, map->exit,i,j);
			if (map->map_array[i][j] == 'C')
				ft_put_image_window(map, map->item,i,j);
			if (map->map_array[i][j] == 'P')
				ft_put_image_window(map, map->player,i,j);
			j++;
		}
		i++;
	}
}