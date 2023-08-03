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
	program_flux(&data, &img, &map, av[1]);
	mlx_loop(data.mlx_display);
	return (0);
}
