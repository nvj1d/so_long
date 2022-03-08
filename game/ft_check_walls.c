/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:18:46 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/08 22:28:42 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_assing(char **dst, char *src, char *to_free)
{
	(*dst) = src;
	free(to_free);
}

int	ft_return(t_map *map)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	r = 1;
	while (i < map->height)
	{
		j = 0;
		if (map->map_array[i][0] != '1' || \
				map->map_array[i][ft_strlen(map->map_array[i]) - 1] != '1')
			r = 0;
		while (map->map_array[i][j] != '\0')
		{
			if (map->map_array[0][j] != '1' || \
				map->map_array[map->height - 1][j] != '1')
				r = 0;
			j++;
		}
		i++;
	}
	return (r);
}

int	ft_check_walls(t_map *map)
{
	int	i;
	int	r;

	i = 0;
	while (i < map->height)
	{
		ft_assing(&map->map_array[i], \
			ft_substr(map->map_array[i], 0, \
			ft_strlen(map->map_array[i]) - 1), map->map_array[i]);
		i++;
	}
	r = ft_return(map);
	return (r);
}
