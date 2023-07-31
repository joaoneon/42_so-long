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



void free_for_finish(t_data *data)
{
	free(data->mlx_display);
}

int	main(int ac, char **av)
{
	// (void)ac;
	if (ac != 2)
		return (0);
	if (check_file_name(av[1]) == 0)
		return (0);
	t_data data;

	t_img img;
	data.images_struct = &img;

	t_map map;
	data.map_struct = &map;

	handle_map(&data, av[1]);
	map_check(&map, &data);

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

	load_images(&data, &img, &map);
	mlx_loop_hook(data.mlx_display, &handle_no_event, &data);
	mlx_hook(data.window, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.window, KeyRelease, KeyReleaseMask, &handle_keyrelease,
			&data);
	mlx_loop(data.mlx_display);

	return (0);
}