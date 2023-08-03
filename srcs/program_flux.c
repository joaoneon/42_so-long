/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_flux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:58:16 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/03 17:47:44 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	program_flux(t_data *data, t_img *img, t_map *map, char *av)
{
	handle_map(data, av);
	map_check(map, data);
	data->mlx_display = mlx_init();
	if (data->mlx_display == NULL)
	{
		free_for_finish(data);
		exit(1);
	}
	data->window = mlx_new_window(data->mlx_display, (data->map_struct->map_x
				- 1) * 64, data->map_struct->map_y * 64,
			"Crash Bandicoot 2D experience");
	if (data->window == NULL)
	{
		free_for_finish(data);
		exit(1);
	}
	data->map_struct->collectables_score = 0;
	data->steps = 0;
	load_images(data, img, map);
	mlx_loop_hook(data->mlx_display, handle_no_event, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		&data);
	mlx_hook(data->window, DestroyNotify, NoEventMask, &handle_x_press, data);
	return (1);
}
