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

void	free_for_finish(t_data *data)
{
	free(data->mlx_display);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (check_file_name(av[1]) == 0)
		return (0);

	t_data data;
	t_img img;
	t_map map;

	data.images_struct = &img;

	data.map_struct = &map;

	handle_map(&data, av[1]);
	map_check(&map, &data);
	program_flux(&data, &img, &map, av[1]);
	mlx_loop(data.mlx_display);

	return (0);
}