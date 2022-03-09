int ft_find_player(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i<map->height)
    {
        j = 0;
        while (j<map->width)
        {
            if (map->map_array[i][j] != 'P')
            {
                map->j = j;
                map->i = i;
                return(1);
            }
            j++;
        }
        i++;
    }
    print i
    print j
    return(1);
}