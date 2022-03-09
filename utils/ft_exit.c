void ft_exit(t_map *map)
{
    mlx_destroy_window(map->mlx,map->mlx_win);
    printf("out of the game!\n");
    exit(0);
}