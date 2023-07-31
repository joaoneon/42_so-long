#include "so_long.h"

void death_animation(t_img *img, t_map *map, t_data *data)
{
    ft_printf("You died, game over <(>_<)>\n");

    (void)img;
    (void)map;
    (void)data;

}

void win_animation(t_img *img, t_map *map, t_data *data)
{
    ft_printf("You WON, well played <(*-*)>\n");
    (void)img;
    (void)map;
    (void)data;
}
