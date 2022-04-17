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
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

# define KEY_ESC 53

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

# define KEY_Q 12
# define KEY_E 14
# define KEY_R 15


typedef struct s_map{
	int		height;
	int		width;
	int		x;
	int		y;
	char	**map_array;
	int		startp;
	int		item;
	int		exit;
}t_map;

typedef struct s_img{
	void	*img_player;
	void	*img_coin;
	void	*img_grass;
	void	*img_dor;
	void	*img_wall;
}t_img;

typedef struct s_game{
	void	*mlx_player;
	void	*win_ptr;
	void	*map;
	void	*img;
	void	*move_count;
}t_game;

//map:
void	ft_map_dim(t_map *path, t_map *map);
char	**ft_map_init(char path, t_map *map);
void	ft_map_chech(t_map *map);

//moves:
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);

//graphic:
void	ft_drawer_init(t_game *game, t_img *img);
void	ft_game_drawer(t_map *map, t_game *game, t_img *img);


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