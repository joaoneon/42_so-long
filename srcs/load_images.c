/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:33:16 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/03 17:33:24 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	put_map(data, map);
}
