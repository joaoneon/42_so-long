#include "so_long.h"

void	death_animation(t_img *img, t_map *map, t_data *data)
{
	ft_printf("You died, game over <(>_<)>\n");
	(void)img;
	(void)map;
	(void)data;
}

void	win_animation(t_img *img, t_map *map, t_data *data)
{
	ft_printf("You WON, well played <(*-*)>\n");
	(void)img;
	(void)map;
	(void)data;
}

void	flood_fill(t_map *map, t_data *data, int x, int y)
{
	char	**mapper;

	mapper = map->map_cpy;
	if (mapper[y][x] == '1' || mapper[y][x] == 'X')
		return ;
	if (mapper[y][x] == 'Z')
		return ;
	mapper[y][x] = 'Z';
	flood_fill(map, data, x, y - 1);
	flood_fill(map, data, x, y + 1);
	flood_fill(map, data, x - 1, y);
	flood_fill(map, data, x + 1, y);
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

void	map_check_p2(t_map *map, t_data *data)
{
	if (map_check_exit(map) != 1)
	{
		ft_printf("There must be 1 exit!\n");
		free(data->window);
		exit(1);
	}
	flood_fill(map, data, 1, 1);
	if (map_check_exit(map) != 0 || map_flood_collectables(map) != 0)
	{
		ft_printf("after flood\n");
		ft_printf("Failed flood fill test!\n");
		free(data->window);
		exit(1);
	}
}
