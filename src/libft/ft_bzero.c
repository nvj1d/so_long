/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:33:55 by mnajid            #+#    #+#             */
/*   Updated: 2021/11/09 17:00:14 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c_s ;
	int		i;

	c_s = (char *)s;
	i = 0;
	while (n--)
	{
		c_s[i] = 0;
		i++;
	}
}
