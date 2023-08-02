/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:57:56 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/02 16:36:12 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_colision_up(t_data *data, t_map *map, int x, int y)
{
	char	**mapper;
	t_img	*img;

	img = data->images_struct;
	mapper = map->map;
	if (mapper[y - 1][x] == '1')
		return (0);
	else if (mapper[y - 1][x] == 'X')
	{
		death_animation(img, map, data);
		free_for_finish(data);
		exit(1);
	}
	else
	{
		img->player_y -= 1;
		check_collectable(img, map, mapper, data);
		check_exit(map, img, mapper, data);
		return (1);
	}
}

int	check_colision_down(t_data *data, t_map *map, int x, int y)
{
	char	**mapper;
	t_img	*img;

	img = data->images_struct;
	mapper = map->map;
	if (mapper[y + 1][x] == '1')
		return (0);
	else if (mapper[y + 1][x] == 'X')
	{
		death_animation(img, map, data);
		free_for_finish(data);
		exit(1);
	}
	else
	{
		img->player_y += 1;
		check_collectable(img, map, mapper, data);
		check_exit(map, img, mapper, data);
		return (1);
	}
}

int	check_colision_left(t_data *data, t_map *map, int x, int y)
{
	char	**mapper;
	t_img	*img;

	img = data->images_struct;
	mapper = map->map;
	if (mapper[y][x - 1] == '1')
		return (0);
	else if (mapper[y][x - 1] == 'X')
	{
		death_animation(img, map, data);
		free_for_finish(data);
		exit(1);
	}
	else
	{
		img->player_x -= 1;
		check_collectable(img, map, mapper, data);
		check_exit(map, img, mapper, data);
		return (1);
	}
}

int	check_colision_right(t_data *data, t_map *map, int x, int y)
{
	char	**mapper;
	t_img	*img;

	img = data->images_struct;
	mapper = map->map;
	if (mapper[y][x + 1] == '1')
		return (0);
	else if (mapper[y][x + 1] == 'X')
	{
		death_animation(img, map, data);
		free_for_finish(data);
		exit(1);
	}
	else
	{
		img->player_x += 1;
		check_collectable(img, map, mapper, data);
		check_exit(map, img, mapper, data);
		return (1);
	}
}
