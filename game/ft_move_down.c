#include"../so_long.h"

void ft_move_up(t_map *map)
{
    ft_find_player(map);
    if (map->map_array[map->i + 1][map->j] == '0')
    {
        map->map_array[map->i + 1][map->j] = 'P';
        map->map_array[map->i][map->j] = '0';
        map->count_moves++;
        ft_printf("%d\n",map->count_moves);
    }
    else if (map->map_array[map->i + 1][map->j] == 'C')
    {
        map->map_array[map->i + 1][map->j] = 'P';
        map->map_array[map->i][map->j] = '0';
        map->count_moves++;
        map->item--;
        ft_printf("%d\n",map->count_moves);
    }
    else if (map->map_array[map->i + 1][map->j] == 'E')
        ft_check_fin(map);   
    else if (map->map_array[map->i + 1][map->j] == '1')
        return ;
    mlx_clear_window(map->mlx, map->mlx_win);
    ft_print_full(map);
}