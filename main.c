/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:41:20 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/07/27 16:52:31 by jpedro-a         ###   ########.fr       */
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
	// printf("teste 1\n");
	data->map_struct->map[index] = NULL;
	// printf("teste 2\n");

	return (1);
}

int	put_map(t_data *data, t_img *img, t_map *map)
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
            
	// printf("teste 3\n");
	
    int pos;
    int arr;
    arr = 0;
    // 0 chão
    // 1 parede
    // E exit
    // C collectable
    // X enemy
	// P player
    
    while (map->map[arr] != NULL)
    {
        pos = 0;
        while(map->map[arr][pos]!= '\0')
        {
            if (map->map[arr][pos] == '1')
            {
                mlx_put_image_to_window(data->mlx_display, data->window, img->wall, (pos*64),
        (arr * 64));
            }
			else if (map->map[arr][pos] == '0')
			{
				mlx_put_image_to_window(data->mlx_display, data->window, img->floor, (pos * 64), (arr * 64));
			}
			else if (map->map[arr][pos] == 'E')
			{
				mlx_put_image_to_window(data->mlx_display, data->window, img->exit, (pos * 64), (arr * 64));
			}
			else if (map->map[arr][pos] == 'C')
			{
				mlx_put_image_to_window(data->mlx_display, data->window, img->collectable, (pos * 64), (arr * 64));
			}
			else if (map->map[arr][pos] == 'X')
			{
				mlx_put_image_to_window(data->mlx_display, data->window, img->enemy, (pos * 64), (arr * 64));
			}
			else if (map->map[arr][pos] == 'P')
			{
				mlx_put_image_to_window(data->mlx_display, data->window, img->player, (pos * 64), (arr * 64));
				img->x = pos * 64;
				img->y = arr * 64;
			}
			pos++;                    
        }
        arr++;
    }
	// printf("teste 4\n");

	return (1);
}

int	main(int ac, char **av)
{
	// (void)ac;
	if (ac != 2)
		exit(1);

	t_data data;

	t_img img;
	data.images_struct = &img;

	t_map map;
	data.map_struct = &map;

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