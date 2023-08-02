/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:57:53 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/02 19:09:01 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s)
{
	char	*s2;
	int		len;
	int		temp;

	len = (int)ft_strlen(s);
	temp = len;
	s2 = malloc((len) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (len-- > 0)
		*s2++ = *s++;
	*s2 = '\0';
	s2 -= temp;
	return (s2);
}

void	copy_map_string(char **str, t_data *data)
{
	int	index;

	index = 0;
	data->map_struct->map_cpy = ft_calloc(sizeof(char *),
			(data->map_struct->map_y + 1));
	while (str[index] != NULL)
	{
		data->map_struct->map_cpy[index] = ft_strdup(str[index]);
		index++;
	}
	data->map_struct->map_cpy[index] = NULL;
}

void	check_collectable(t_img *img, t_map *map, char **mapper, t_data *data)
{
	int	x;
	int	y;

	x = img->player_x;
	y = img->player_y;
	(void)data;
	if (mapper[y][x] == 'C')
	{
		map->collectables_score += 1;
		mapper[y][x] = '0';
		ft_printf("score: %i\n", map->collectables_score);
		if (map->collectables_score == map->collectables_amount)
		{
			mlx_put_image_to_window(data->mlx_display, data->window, img->exit,
				(map->exit_x * 64), (map->exit_y * 64));
			map->exit_signal = 1;
		}
	}
}

void	check_exit(t_map *map, t_img *img, char **mapper, t_data *data)
{
	int	x;
	int	y;

	x = img->player_x;
	y = img->player_y;
	if (mapper[y][x] == 'E' && map->exit_signal == 1)
	{
		win_animation(img, map, data);
		free_for_finish(data);
		exit(1);
	}
}

int	check_colision(int keysym, t_data *data, t_img *img, t_map *map)
{
	int	x;
	int	y;

	x = img->player_x;
	y = img->player_y;
	if (keysym == 119 || keysym == XK_Up)
	{
		return (check_colision_up(data, map, x, y));
	}
	if (keysym == 115 || keysym == XK_Down)
	{
		return (check_colision_down(data, map, x, y));
	}
	if (keysym == 97 || keysym == XK_Left)
	{
		return (check_colision_left(data, map, x, y));
	}
	if (keysym == 100 || keysym == XK_Right)
	{
		return (check_colision_right(data, map, x, y));
	}
	return (0);
}
