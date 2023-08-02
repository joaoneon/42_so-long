/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:41:20 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/02 19:10:44 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free(map->map);
	free(map->map_cpy);
}

void	free_images(t_data *data)
{
	t_img	*img;

	img = data->images_struct;
	mlx_destroy_image(data->mlx_display, img->player);
	mlx_destroy_image(data->mlx_display, img->player_u);
	mlx_destroy_image(data->mlx_display, img->player_l);
	mlx_destroy_image(data->mlx_display, img->player_r);
	mlx_destroy_image(data->mlx_display, img->floor);
	mlx_destroy_image(data->mlx_display, img->wall);
	mlx_destroy_image(data->mlx_display, img->collectable);
	mlx_destroy_image(data->mlx_display, img->enemy);
	mlx_destroy_image(data->mlx_display, img->exit);
}

void	get_player_pos(t_data *data)
{
	int		y;
	int		x;
	char	**mapper;

	mapper = data->map_struct->map;
	y = 0;
	while (mapper[y] != NULL)
	{
		x = 0;
		while (mapper[y][x] != '\0')
		{
			if (mapper[y][x] == 'P')
			{
				data->map_struct->player_x = x;
				data->map_struct->player_y = y;
			}
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_img	img;
	t_map	map;

	if (ac != 2)
		return (0);
	if (check_file_name(av[1]) == 0)
		return (0);
	data.images_struct = &img;
	data.map_struct = &map;
	handle_map(&data, av[1]);
	map_check(&map, &data);
	program_flux(&data, &img, &map, av[1]);
	mlx_loop(data.mlx_display);
	return (0);
}
