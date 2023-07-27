/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:41:20 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/07/27 14:12:21 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_map(t_data *data, char *map_name)
{
	int		fd;
	char	*str;
	int		signal;
	int		index;

	fd = open(map_name, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (0);
	signal = 0;
	data->map_struct->map_x = ft_strlen(str);
	data->map_struct->map_y = 1;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if ((ft_strlen(str) != data->map_struct->map_x)
			&& (str[data->map_struct->map_x - 1] != '\0'))
		{
			signal = 1;
		}
		data->map_struct->map_y++;
	}
	if (signal = 1)
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
	data->map_struct->map[index] == NULL;
	return (1);
}

int	put_map(t_data *data, t_img *img, t_map *map)
{
	img->player = mlx_xpm_file_to_image(data->mlx_display, PLAYER,
			data->images_struct->img_height, img->img_height);
	img->floor = mlx_xpm_file_to_image(data->mlx_display, FLOOR,
			img->img_height, img->img_height);
	img->wall = mlx_xpm_file_to_image(data->mlx_display, WALL, img->img_height,
			img->img_height);
	img->enemy = mlx_xpm_file_to_image(data->mlx_display, ENEMY,
			img->img_height, img->img_height);
	img->collectable = mlx_xpm_file_to_image(data->mlx_display, COLLECTABLE,
			img->img_height, img->img_height);
	img->exit = mlx_xpm_file_to_image(data->mlx_display, EXIT, img->img_height,
			img->img_height);
            
    int pos;
    int arr;
    arr = 0;
    // 0
    // 1
    // E
    // C
    // X
    
    while (map->map[arr] != NULL)
    {
        pos = 0;
        while(map->map[arr][pos]!= '\0')
        {
            if (map->map[arr][pos] == 'P')
            {
                mlx_put_image_to_window(data->mlx_display, data->window, img->player, (pos*64),
        (arr * 64));
            }
                    
        }
        
    }
    mlx_put_image_to_window(data->mlx_display, data->window, img->player, img->x,
        img->y);
}

int	main(int ac, char **av)
{
	(void)ac;

	t_data data;

	t_img img;
	data.images_struct = &img;

	t_map map;
	data.map_struct = &map;

	img.x = 0;
	img.y = 0;
	data.mlx_display = mlx_init();
	if (data.mlx_display == NULL)
		return (MLX_ERROR);
	data.window = mlx_new_window(data.mlx_display, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Crash Bandicoot 2D experience");
	if (data.window == NULL)
	{
		free(data.window);
		return (MLX_ERROR);
	}

	handle_map(&data, av[1]);
	put_map(&data, &img, &map);
	mlx_loop_hook(data.mlx_display, &handle_no_event, &data);
	mlx_hook(data.window, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.window, KeyRelease, KeyReleaseMask, &handle_keyrelease,
			&data);
	mlx_loop(data.mlx_display);

	return (0);
}