/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:25:32 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/08 21:25:32 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_collect_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_array[i][j] == 'P')
				map->startp += 1;
			if (map->map_array[i][j] == 'C')
				map->item += 1;
			if (map->map_array[i][j] == 'E')
				map->exit += 1;
			j++;
		}
		i++;
	}
	if (map->item < 1 || map->exit < 1 || map->startp != 1)
		ft_error(1, map);
}
