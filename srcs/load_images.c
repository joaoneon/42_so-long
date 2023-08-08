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
	img->death_1 = mlx_xpm_file_to_image(data->mlx_display, DEATH_1,
			&img->img_width, &img->img_height);
	img->death_2 = mlx_xpm_file_to_image(data->mlx_display, DEATH_2,
			&img->img_width, &img->img_height);
	load_images_2(data, img);
	put_map(data, map);
}

void	load_images_2(t_data *data, t_img *img)
{
	img->death_3 = mlx_xpm_file_to_image(data->mlx_display, DEATH_3,
			&img->img_width, &img->img_height);
	img->death_4 = mlx_xpm_file_to_image(data->mlx_display, DEATH_4,
			&img->img_width, &img->img_height);
	img->death_5 = mlx_xpm_file_to_image(data->mlx_display, DEATH_5,
			&img->img_width, &img->img_height);
	img->death_6 = mlx_xpm_file_to_image(data->mlx_display, DEATH_6,
			&img->img_width, &img->img_height);
	img->exit_1 = mlx_xpm_file_to_image(data->mlx_display, EXIT_1,
			&img->img_width, &img->img_height);
	img->exit_2 = mlx_xpm_file_to_image(data->mlx_display, EXIT_2,
			&img->img_width, &img->img_height);
	img->exit_3 = mlx_xpm_file_to_image(data->mlx_display, EXIT_3,
			&img->img_width, &img->img_height);
	img->exit_4 = mlx_xpm_file_to_image(data->mlx_display, EXIT_4,
			&img->img_width, &img->img_height);
	img->exit_5 = mlx_xpm_file_to_image(data->mlx_display, EXIT_5,
			&img->img_width, &img->img_height);
	img->exit_6 = mlx_xpm_file_to_image(data->mlx_display, EXIT_6,
			&img->img_width, &img->img_height);
	img->exit_7 = mlx_xpm_file_to_image(data->mlx_display, EXIT_7,
			&img->img_width, &img->img_height);
	data->map_struct->crate_steps = mlx_xpm_file_to_image(data->mlx_display,
			CRATE, &img->img_width, &img->img_height);
}
