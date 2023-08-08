/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:57:53 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/03 16:15:46 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_for_finish(t_data *data)
{
	free_images(data);
	free_images_2(data);
	free_images_3(data);
	mlx_destroy_window(data->mlx_display, data->window);
	mlx_destroy_display(data->mlx_display);
	free_maps(data);
	free(data->mlx_display);
}

void	free_maps(t_data *data)
{
	t_map	*map;

	map = data->map_struct;
	if (map->map != NULL || map->map_cpy != NULL)
		free_map(data);
}

void	free_map(t_data *data)
{
	t_map	*map;
	int		i;

	map = data->map_struct;
	i = -1;
	if (map->map != NULL)
	{
		while (++i < map->map_y)
			free(map->map[i]);
		free(map->map);
	}
	i = -1;
	if (map->map_cpy != NULL)
	{
		while (++i < map->map_y)
			free(map->map_cpy[i]);
		free(map->map_cpy);
	}
}

void	free_images(t_data *data)
{
	t_img	*img;

	img = data->images_struct;
	if (img->player != NULL)
		mlx_destroy_image(data->mlx_display, img->player);
	if (img->player_u != NULL)
		mlx_destroy_image(data->mlx_display, img->player_u);
	if (img->player_l != NULL)
		mlx_destroy_image(data->mlx_display, img->player_l);
	if (img->player_r != NULL)
		mlx_destroy_image(data->mlx_display, img->player_r);
	if (img->floor != NULL)
		mlx_destroy_image(data->mlx_display, img->floor);
	if (img->wall != NULL)
		mlx_destroy_image(data->mlx_display, img->wall);
	if (img->collectable != NULL)
		mlx_destroy_image(data->mlx_display, img->collectable);
	if (img->enemy != NULL)
		mlx_destroy_image(data->mlx_display, img->enemy);
	if (img->exit != NULL)
		mlx_destroy_image(data->mlx_display, img->exit);
	if (data->map_struct->crate_steps != NULL)
		mlx_destroy_image(data->mlx_display, data->map_struct->crate_steps);
}

void	free_images_2(t_data *data)
{
	t_img	*img;

	img = data->images_struct;
	if (img->death_1 != NULL)
		mlx_destroy_image(data->mlx_display, img->death_1);
	if (img->death_2 != NULL)
		mlx_destroy_image(data->mlx_display, img->death_2);
	if (img->death_3 != NULL)
		mlx_destroy_image(data->mlx_display, img->death_3);
	if (img->death_4 != NULL)
		mlx_destroy_image(data->mlx_display, img->death_4);
	if (img->death_5 != NULL)
		mlx_destroy_image(data->mlx_display, img->death_5);
	if (img->death_6 != NULL)
		mlx_destroy_image(data->mlx_display, img->death_6);
	if (img->exit_1 != NULL)
		mlx_destroy_image(data->mlx_display, img->exit_1);
	if (img->exit_2 != NULL)
		mlx_destroy_image(data->mlx_display, img->exit_2);
	if (img->exit_3 != NULL)
		mlx_destroy_image(data->mlx_display, img->exit_3);
	if (img->exit_4 != NULL)
		mlx_destroy_image(data->mlx_display, img->exit_4);
}
