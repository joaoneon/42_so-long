#include "so_long.h"

void	put_player_enemy(char c, t_data *data, t_img *img, int pos, int arr)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx_display, data->window, img->player,
			(pos * 64), (arr * 64));
		img->x = pos * 64;
		img->y = arr * 64;
		img->player_x = pos;
		img->player_y = arr;
	}
	if (c == 'E')
	{
		data->map_struct->exit_x = pos;
		data->map_struct->exit_y = arr;
		mlx_put_image_to_window(data->mlx_display, data->window, img->floor,
			(pos * 64), (arr * 64));
		data->map_struct->exit_signal = 0;
	}
}

int	put_map(t_data *data, t_img *img, t_map *map)
{
	int	pos;
	int	arr;

	arr = -1;
	while (map->map[++arr] != NULL)
	{
		pos = -1;
		while (map->map[arr][++pos] != '\0')
		{
			if (map->map[arr][pos] == '1')
				put_map_aux(data, img, map->map[arr][pos], pos, arr);
			else if (map->map[arr][pos] == '0')
                put_map_aux(data, img, map->map[arr][pos], pos, arr);
			else if (map->map[arr][pos] == 'C')
				put_map_aux(data, img, map->map[arr][pos], pos, arr);
			else if (map->map[arr][pos] == 'X')
                put_map_aux(data, img, map->map[arr][pos], pos, arr);
			else if (map->map[arr][pos] == 'P')
				put_player_enemy('P', data, img, pos, arr);
			else if (map->map[arr][pos] == 'E')
				put_player_enemy('E', data, img, pos, arr);
		}
	}
	return (1);
}

void	put_map_aux(t_data *data, t_img *img, char c, int pos, int arr)
{
	if (c == '1')
	{
		mlx_put_image_to_window(data->mlx_display, data->window, img->wall, (pos
				* 64), (arr * 64));
	}
	else if (c == '0')
	{
		mlx_put_image_to_window(data->mlx_display, data->window, img->floor,
			(pos * 64), (arr * 64));
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx_display, data->window,
			img->collectable, (pos * 64), (arr * 64));
	}
	else if (c == 'X')
	{
		mlx_put_image_to_window(data->mlx_display, data->window, img->enemy,
			(pos * 64), (arr * 64));
	}
}
