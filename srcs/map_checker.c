/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:58:08 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/08 16:21:23 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(t_map *map, t_data *data)
{
	if (map_check_retangular(map) == 1)
	{
		free_maps(data);
		exit(1);
	}
	if (map_check_characters(map) != 0)
	{
		ft_printf("Character not allowed\n");
		free_maps(data);
		exit(1);
	}
	if (map_check_walls(map) == 0)
	{
		ft_printf("Map not surrounded by walls\n");
		free_maps(data);
		exit(1);
	}
	if (map_check_players(map) != 1)
	{
		ft_printf("Game has to have 1 player\n");
		free_maps(data);
		exit(1);
	}
	map_check_p2(map, data);
	return (1);
}

int	map_check_characters(t_map *map)
{
	int		characters;
	char	**mapper;
	int		x;
	int		y;
	int		max_y;

	max_y = map->map_y - 1;
	y = 0;
	characters = 0;
	mapper = map->map_cpy;
	while (y <= max_y)
	{
		x = 0;
		while (mapper[y][x] != '\0' && mapper[y][x] != '\n')
		{
			if (mapper[y][x] != '1' && mapper[y][x] != 'C'
				&& mapper[y][x] != '0' && mapper[y][x] != 'X'
				&& mapper[y][x] != 'E' && mapper[y][x] != '\n'
				&& mapper[y][x] != '\0' && mapper[y][x] != 'P')
				characters++;
			x++;
		}
		y++;
	}
	return (characters);
}

int	map_check_walls(t_map *map)
{
	int		x;
	int		y;
	int		max_x;
	int		max_y;
	char	**mapper;

	mapper = map->map;
	x = -1;
	y = -1;
	max_x = map->map_x;
	max_y = map->map_y;
	while (++x <= max_x - 2)
		if (mapper[0][x] != '1')
			return (0);
	while (++y < max_y)
		if (mapper[y][0] != '1' || mapper[y][max_x - 2] != '1')
			return (0);
	x = -1;
	while (mapper[max_y - 1][++x] != '\0')
		if (mapper[max_y - 1][x] != '1')
			return (0);
	return (1);
}

int	map_check_players(t_map *map)
{
	int		players;
	char	**mapper;
	int		x;
	int		y;
	int		max_y;

	max_y = map->map_y - 1;
	y = 0;
	players = 0;
	mapper = map->map_cpy;
	while (y <= max_y)
	{
		x = 0;
		while (mapper[y][x] != '\0' && mapper[y][x] != '\n')
		{
			if (mapper[y][x] == 'P')
				players++;
			x++;
		}
		y++;
	}
	return (players);
}

int	check_file_name(char *str)
{
	int	fd;
	int	size;
	int	x;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Couldn't open the map, verify the name of the file \n");
		return (0);
	}
	size = ft_strlen(str);
	x = size - 4;
	if (str[x] != '.' || str[x + 1] != 'b' || str[x + 2] != 'e' || str[x
			+ 3] != 'r')
	{
		ft_printf("Map format needs to be .ber\n");
		return (0);
	}
	return (1);
}
