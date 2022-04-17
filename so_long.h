/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:29:27 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/07 20:29:27 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

typedef struct s_map{
	int		height;
	int		width;
	int		x;
	int		y;
	int		count_moves;
	char	**map_array;
	void	*mlx;
	void	*mlx_win;
	int		startp;
	int		item;
	int		exit;
	char	*player;
	int		font_w;
	int		font_h;
	int		empty;
	int		wall;
}t_map; 

//help:
char	*get_next_line(int fd);
//get next line utils:√

// printf
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

void	ft_error(int n, t_map *map);
void	ft_free(t_map *map);
void	ft_init(t_map *map);

void	ft_check_map(t_map *map, char *str);
void	ft_fill_map_array(t_map *map, char *path_map);
int		ft_check_walls(t_map *map);
int		ft_check_rectangle(t_map *map);
char	*ft_getpath(char *str);
void	ft_collect_map(t_map *map);
#endif