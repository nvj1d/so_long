/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:26:05 by mnajid            #+#    #+#             */
/*   Updated: 2022/04/17 22:36:20 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_init(char *path, t_map *map)
{
	int		fd;
	int		i;
	int		*line;
	char	**map_arr;

	ft_extention_valid(path);
	ft_map_dim(path, map);
	map_arr = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map_arr)
		return (NULL);
	fd = open(path,O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map_arr[i] = ft_strdup(line);
		if (!map_arr[i])
			return (NULL);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map_arr[map->height] = NULL;
	close(fd);
	return (map_arr);
}
