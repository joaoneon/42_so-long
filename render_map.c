#include "so_long.h"

int	handle_map(t_data *data, char *map_name)
{
	int		fd;
	char	*str;
	int		signal;
	int		index;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		exit (1);
	}
	str = get_next_line(fd);
	if (str == NULL)
		return (0);
	signal = 0;
	data->map_struct->map_x = (int)ft_strlen(str);
	data->map_struct->map_y = 1;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			break;
		if (((int)ft_strlen(str) != data->map_struct->map_x)
			&& (str[data->map_struct->map_x - 1] != '\0'))
		{
			signal = 1;
		}
		data->map_struct->map_y++;
	}
	if (signal == 1)
	{
		close(fd);
		ft_printf("O mapa não é retangular");
		return (0);
	}
	close(fd);
	data->map_struct->map = malloc((data->map_struct->map_y + 1)
			* sizeof(char *));
	index = 0;
	fd = open(map_name, O_RDONLY);
	while (index < data->map_struct->map_y)
	{
		data->map_struct->map[index] = get_next_line(fd);
		index++;
	}
	close(fd);
	data->map_struct->map[index] = NULL;
	copy_map_string(data->map_struct->map, data);
	return (1);
}

void load_images(t_data *data, t_img *img, t_map *map)
{
	img->player = mlx_xpm_file_to_image(data->mlx_display, PLAYER,
		&data->images_struct->img_width, &img->img_height);
	img->floor = mlx_xpm_file_to_image(data->mlx_display, FLOOR,
			&img->img_width, &img->img_height);
	img->wall = mlx_xpm_file_to_image(data->mlx_display, WALL, &img->img_width,
			&img->img_height);
	img->enemy = mlx_xpm_file_to_image(data->mlx_display, ENEMY,
			&img->img_width, &img->img_height);
	img->collectable = mlx_xpm_file_to_image(data->mlx_display, COLLECTABLE,
			&img->img_width, &img->img_height);
	img->exit = mlx_xpm_file_to_image(data->mlx_display, EXIT, &img->img_width,
			&img->img_height);
            
	put_map(data, img, map);
}

void put_player_enemy(char c, t_data *data, t_img *img, int pos, int arr)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx_display, data->window, img->player, (pos * 64), (arr * 64));
		img->x = pos * 64;
		img->y = arr * 64;
		img->player_x = pos;
		img->player_y = arr;
	}
	if (c == 'E')
	{
		data->map_struct->exit_x = pos;
		data->map_struct->exit_y = arr;
		mlx_put_image_to_window(data->mlx_display, data->window, img->floor, (pos * 64), (arr * 64));
		data->map_struct->exit_signal = 0;
	}
}

int	put_map(t_data *data, t_img *img, t_map *map)
{	
    int pos;
    int arr;
    arr = -1;
    
    while (map->map[++arr] != NULL)
    {
        pos = -1;
        while(map->map[arr][++pos]!= '\0')
        {
            if (map->map[arr][pos] == '1')
                mlx_put_image_to_window(data->mlx_display, data->window, img->wall, (pos*64), (arr * 64));
			else if (map->map[arr][pos] == '0')
				mlx_put_image_to_window(data->mlx_display, data->window, img->floor, (pos * 64), (arr * 64));
			else if (map->map[arr][pos] == 'C')
			{
				mlx_put_image_to_window(data->mlx_display, data->window, img->collectable, (pos * 64), (arr * 64));
			}
			else if (map->map[arr][pos] == 'X')
				mlx_put_image_to_window(data->mlx_display, data->window, img->enemy, (pos * 64), (arr * 64));
			else if (map->map[arr][pos] == 'P')
				put_player_enemy('P', data, img, pos, arr);        
			else if (map->map[arr][pos] == 'E')
				put_player_enemy('E', data, img, pos, arr);
        }
    }
	return (1);
}
