/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:37:33 by mnajid            #+#    #+#             */
/*   Updated: 2022/04/17 23:43:18 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walls(t_map *map)
{
	int		i;
	int		j;
	int		rows;
	int		columns;
	char	**map_arr;

	rows = map->height - 1;
	columns = map->width - 1;
	map_arr = map->map_array;
	i = -1;
	while (++i <= rows)
	{
		j = -1;
		while (++j <= columns)
		{
			if (map_arr[0][j] != '1' || map_arr[rows][j] != '1'
				|| map_arr[i][0] != '1' || map_arr[i][columns] != '1')
				ft_map_errors(map, 3);
		}
	}
}

void	ft_check_rect(t_map *map, char c, int i, int j)
{
	int		i;
	char	**map_arr;

	map_arr = map->map_array;
	i = -1;
	while (map_arr[++i])
	{
		if ((int)ft_strlen(map_arr[i] - 1) != map->width)
			ft_map_errors();
	}
}


void	ft_map_chars_num(t_map *map, char c, int i, int j)
{
	if(c == '0' || c == '1')
		return;
	else if (c == 'E')
		map->item++;
	else if (c == 'P')
	{
		map->startp++;
		map->x = j;
		map->y = i;
	}
}

//to check if the map is valid or not!
void	ft_map_check(t_map *tmap)
{
	int		i;
	int		j;
	char	**map;

	ft_check_rect(tmap);
	map = tmap->map_array;
	i = -1;
	tmap->exit = 0;
	tmap->item = 0;
	tmap->startp = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
				ft_map_error(tmap,1);
			ft_map_chars_num(tmap, map[i][j], i, j);
		}
	}
	if (tmap->exit <= 0 || tmap->item <= 0 || tmap->startp != 1)
		ft_map_errors(tmap, 2);
	ft_check_walls(tmap);
}