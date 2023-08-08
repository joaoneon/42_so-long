/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:58:23 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/03 17:48:39 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_flood_collectables(t_map *map)
{
	int		collectables;
	char	**mapper;
	int		x;
	int		y;

	y = 0;
	collectables = 0;
	mapper = map->map_cpy;
	while (mapper[y] != NULL)
	{
		x = 0;
		while (mapper[y][x] != '\0' && mapper[y][x] != '\n')
		{
			if (mapper[y][x] == 'C')
				collectables++;
			x++;
		}
		y++;
	}
	return (collectables);
}

void	free_images_3(t_data *data)
{
	t_img	*img;

	img = data->images_struct;
	if (img->exit_5 != NULL)
		mlx_destroy_image(data->mlx_display, img->exit_5);
	if (img->exit_6 != NULL)
		mlx_destroy_image(data->mlx_display, img->exit_6);
	if (img->exit_7 != NULL)
		mlx_destroy_image(data->mlx_display, img->exit_7);
}
