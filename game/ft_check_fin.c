void ft_check_fin()
{
    if(map->item == 0)
    {
        mlx_clear_window(mlx,win);
        mlx_destroy_window(mlx,win);
        map->count_move++;
        ft_printf("you win!\n");
        exit(0);
    }
}