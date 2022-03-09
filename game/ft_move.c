#include "../so_long.h"

int ft_move(int key, t_map *map)
{
    if (key == 13)
        ft_move_up(map);
    else if (key == 1)
        ft_move_down(map);
    else if (key == 2)
        ft_move_left(map);
    else if (key == 0)
        ft_move_right(map);
    else if (key == 53)
        ft_exit(map);
    return(0);
}
