#include "so_long.h"

void	handle_map2(t_data *data, int fd, char *str)
{
	int	signal;

	signal = 0;
	data->map_struct->map_x = (int)ft_strlen(str);
	data->map_struct->map_y = 1;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			break ;
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
		exit(1);
	}
}

int	handle_map(t_data *data, char *map_name)
{
	int		fd;
	char	*str;
	int		index;

	fd = open(map_name, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (0);
	handle_map2(data, fd, str);
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

void	load_images(t_data *data, t_img *img, t_map *map)
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
	img->player_u = mlx_xpm_file_to_image(data->mlx_display, PLAYER_U,
		&data->images_struct->img_width, &data->images_struct->img_height);
	img->player_l = mlx_xpm_file_to_image(data->mlx_display, PLAYER_L,
		&data->images_struct->img_width, &data->images_struct->img_height);
	img->player_r = mlx_xpm_file_to_image(data->mlx_display, PLAYER_R,
		&data->images_struct->img_width, &data->images_struct->img_height);
	put_map(data, img, map);
}

int	map_flood_collectables(t_map *map)
{
	int collectables;
	char **mapper;
	int x;
	int y;
	int max_y;

	max_y = map->map_y - 1;
	y = 0;
	collectables = 0;
	mapper = map->map_cpy;
	while (y <= max_y)
	{
		x = 0;
		while (mapper[y][x] != '\0' && mapper[y][x] != '\n')
		{
			if (mapper[y][x] == 'C')
				collectables++;
			x++;
		}
		y++;
	}
	return (collectables);
}