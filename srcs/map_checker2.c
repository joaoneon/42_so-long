/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:06:15 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/03 17:48:18 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_p2(t_map *map, t_data *data)
{
	if (map_check_collectables(map) <= 0)
	{
		ft_printf("Game needs at least one collectable\n");
		free_maps(data);
		exit(1);
	}
	if (map_check_exit(map) != 1)
	{
		ft_printf("There must be 1 exit!\n");
		free_maps(data);
		exit(1);
	}
	get_player_pos(data);
	flood_fill(map, data, map->player_x, map->player_y);
	if (map_check_exit(map) != 0 || map_flood_collectables(map) != 0)
	{
		ft_printf("Failed flood fill test!\n");
		free_maps(data);
		exit(1);
	}
}

int	map_check_collectables(t_map *map)
{
	int		collectables;
	char	**mapper;
	int		x;
	int		y;
	int		max_y;

	max_y = map->map_y - 1;
	y = 0;
	collectables = 0;
	mapper = map->map;
	while (y <= max_y)
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
	map->collectables_amount = collectables;
	return (collectables);
}

int	map_check_exit(t_map *map)
{
	int		exits;
	char	**mapper;
	int		x;
	int		y;
	int		max_y;

	max_y = map->map_y - 1;
	y = 0;
	exits = 0;
	mapper = map->map_cpy;
	while (y <= max_y)
	{
		x = 0;
		while (mapper[y][x] != '\0' && mapper[y][x] != '\n')
		{
			if (mapper[y][x] == 'E')
				exits++;
			x++;
		}
		y++;
	}
	return (exits);
}

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

void	flood_fill(t_map *map, t_data *data, int x, int y)
{
	char	**mapper;

	mapper = map->map_cpy;
	if (mapper[y][x] == '1' || mapper[y][x] == 'X')
		return ;
	if (mapper[y][x] == 'Z')
		return ;
	if (mapper[y][x] != '\0')
		mapper[y][x] = 'Z';
	flood_fill(map, data, x, y - 1);
	flood_fill(map, data, x, y + 1);
	flood_fill(map, data, x - 1, y);
	flood_fill(map, data, x + 1, y);
}
