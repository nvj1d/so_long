/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:55:27 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/07 20:55:27 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	if (!map->map_array[0])
		return ;
	while (map->map_array[i++])
		free(map->map_array[i]);
	free(map->map_array[i]);
}
