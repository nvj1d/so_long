/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:37:33 by mnajid            #+#    #+#             */
/*   Updated: 2022/04/17 22:51:38 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
ft_map_chars_num()
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