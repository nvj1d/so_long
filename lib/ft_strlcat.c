/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:48:09 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/08 20:48:24 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	s;
	size_t	i;

	j = 0;
	if (ft_strlen(dest) >= size)
	{
		return (size + ft_strlen(src));
	}
	else
	{
		j = ft_strlen(dest);
		i = ft_strlen(dest);
		s = 0;
		while (src[s] && j < size - 1)
		{
			dest[j] = src[s];
			s++;
			j++;
		}
		dest[j] = '\0';
		return (i + ft_strlen(src));
	}
}
