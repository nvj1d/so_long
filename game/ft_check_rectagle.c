/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rectagle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:17:49 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/08 21:38:21 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_rectangle(t_map *map)
{
	size_t	len;
	int		i;
	int		r;

	i = 0;
	r = 1;
	len = ft_strlen(map->map_array[0]);
	while (i < map->height - 1)
	{
		if (len != ft_strlen(map->map_array[i]))
			r = 0;
		i++;
	}
	return (r);
}
