/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_resources.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:48:35 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/02 14:59:13 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_data *data)
{
	(void)data;
	return (0);
}

void	handle_movement(int keysym, t_data *data, t_img *img, t_map *map)
{
	ft_printf("Pressed key: %d\n", keysym);
	if ((keysym == 119 || keysym == XK_Up) && (check_colision(keysym, data, img,
				map)))
	{
		move_up(data);
	}
	if ((keysym == 97 || keysym == XK_Left) && (check_colision(keysym, data,
				img, map)))
	{
		move_left(data);
	}
	if ((keysym == 115 || keysym == XK_Down) && (check_colision(keysym, data,
				img, map)))
	{
		move_down(data);
	}
	if ((keysym == 100 || keysym == XK_Right) && (check_colision(keysym, data,
				img, map)))
	{
		move_right(data);
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	t_map	*map;
	t_img	*img;

	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_display, data->window);
		mlx_destroy_display(data->mlx_display);
		free(data->mlx_display);
		ft_printf("Pressed key: %d\n", keysym);
		exit(0);
	}
	map = data->map_struct;
	img = data->images_struct;
	handle_movement(keysym, data, img, map);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	(void)*data;
	(void)keysym;
	return (0);
}
