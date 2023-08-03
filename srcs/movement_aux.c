/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:58:12 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/02 16:40:02 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	data->images_struct->back_y = data->images_struct->y;
	data->images_struct->y -= 64;
	mlx_put_image_to_window(data->mlx_display, data->window,
		data->images_struct->floor, data->images_struct->x,
		data->images_struct->back_y);
	mlx_put_image_to_window(data->mlx_display, data->window,
		data->images_struct->player_u, data->images_struct->x,
		data->images_struct->y);
	data->steps += 1;
	ft_printf("Steps: %d\n", data->steps);
}

void	move_left(t_data *data)
{
	data->images_struct->back_x = data->images_struct->x;
	data->images_struct->x -= 64;
	mlx_put_image_to_window(data->mlx_display, data->window,
		data->images_struct->floor, data->images_struct->back_x,
		data->images_struct->y);
	mlx_put_image_to_window(data->mlx_display, data->window,
		data->images_struct->player_l, data->images_struct->x,
		data->images_struct->y);
	data->steps += 1;
	ft_printf("Steps: %d\n", data->steps);
}

void	move_down(t_data *data)
{
	data->images_struct->back_y = data->images_struct->y;
	data->images_struct->y += 64;
	mlx_put_image_to_window(data->mlx_display, data->window,
		data->images_struct->floor, data->images_struct->x,
		data->images_struct->back_y);
	mlx_put_image_to_window(data->mlx_display, data->window,
		data->images_struct->player, data->images_struct->x,
		data->images_struct->y);
	data->steps += 1;
	ft_printf("Steps: %d\n", data->steps);
}

void	move_right(t_data *data)
{
	data->images_struct->back_x = data->images_struct->x;
	data->images_struct->x += 64;
	mlx_put_image_to_window(data->mlx_display, data->window,
		data->images_struct->floor, data->images_struct->back_x,
		data->images_struct->y);
	mlx_put_image_to_window(data->mlx_display, data->window,
		data->images_struct->player_r, data->images_struct->x,
		data->images_struct->y);
	data->steps += 1;
	ft_printf("Steps: %d\n", data->steps);
}
