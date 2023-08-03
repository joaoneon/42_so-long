#include "so_long.h"

void	free_for_finish(t_data *data)
{
	free_images(data);
	mlx_destroy_window(data->mlx_display, data->window);
	mlx_destroy_display(data->mlx_display);
	free_maps(data);
	free(data->mlx_display);
}

void	free_maps(t_data *data)
{
	t_map	*map;

	map = data->map_struct;
	if (map->map != NULL)
		free_map(data);
}


void	free_map(t_data *data)
{
    t_map *map;
	int	i;

    map = data->map_struct;
	i = -1;
	while (++i < map->map_y)
		free(map->map[i]);
	free(map->map);
    i = -1;
	while (++i < map->map_y)
		free(map->map_cpy[i]);
	free(map->map_cpy);
}

void	free_images(t_data *data)
{
	t_img	*img;

	img = data->images_struct;
	if (img->player != NULL)
		mlx_destroy_image(data->mlx_display, img->player);
	if (img->player_u != NULL)
		mlx_destroy_image(data->mlx_display, img->player_u);
	if (img->player_l != NULL)
		mlx_destroy_image(data->mlx_display, img->player_l);
	if (img->player_r != NULL)
		mlx_destroy_image(data->mlx_display, img->player_r);
	if (img->floor != NULL)
		mlx_destroy_image(data->mlx_display, img->floor);
	if (img->wall != NULL)
		mlx_destroy_image(data->mlx_display, img->wall);
	if (img->collectable != NULL)
		mlx_destroy_image(data->mlx_display, img->collectable);
	if (img->enemy != NULL)
		mlx_destroy_image(data->mlx_display, img->enemy);
	if (img->exit != NULL)
		mlx_destroy_image(data->mlx_display, img->exit);
}