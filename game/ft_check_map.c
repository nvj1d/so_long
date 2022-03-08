/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:58:18 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/07 20:58:18 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_getpath(char *str)
{
	char	*ptr;
	char	*ret;

	ret = NULL;
	ptr = ft_strchr(str, '.');
	if (ft_strncmp(ptr, ".ber", 5) != 0)
		ft_error(0, NULL);
	else
		ret = ft_strjoin("maps/", str);
	return (ret);
}

void	ft_fill_map_array(t_map *map, char *path_map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	map->map_array = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->map_array)
		ft_error(1, map);
	fd = open(path_map, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->map_array[i++] = line;
	}
	map->map_array[i] = NULL; //√
	close(fd);
}

int	ft_getheight(char *str)
{
	char	*line;
	int		ret;
	int		fd;

	ret = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error(0, NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ret += 1;
	}
	free(line);
	close(fd);
	return (ret);
}

void	ft_check_map(t_map *map, char *str)
{
	char	*path_map;

	path_map = ft_getpath(str);
	map->height = ft_getheight(path_map); //√
	ft_fill_map_array(map, path_map);
	map->width = ft_strlen(map->map_array[0]);
	if (!ft_check_walls(map) || !ft_check_rectangle(map))
		ft_error(1, map);
	// ft_collect_map(map);
	// free(path_map);
	// printf("the map is good!\n");
}
