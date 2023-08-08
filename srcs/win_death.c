/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_death.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:58:31 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/03 17:40:47 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	death_animation(t_img *img, t_map *map, t_data *data)
{
	int	i;
	int	pos;
	int	arr;

	i = -1;
	pos = img->player_x;
	arr = img->player_y;
	put_death_animation(i, data, img);
	while (++i < 5000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->floor,
			(pos * 64), (arr * 64));
	ft_printf("You died, game over <(>_<)>\n");
	(void)map;
}

void	put_death_animation(int i, t_data *data, t_img *img)
{
	int	pos;
	int	arr;

	pos = img->player_x;
	arr = img->player_y;
	while (++i < 25000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->death_1,
			(pos * 64), (arr * 64));
	while (++i < 50000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->death_2,
			(pos * 64), (arr * 64));
	while (++i < 75000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->death_3,
			(pos * 64), (arr * 64));
	while (++i < 100000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->death_4,
			(pos * 64), (arr * 64));
	while (++i < 125000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->death_5,
			(pos * 64), (arr * 64));
	while (++i < 150000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->death_6,
			(pos * 64), (arr * 64));
}

void	win_animation(t_img *img, t_map *map, t_data *data)
{
	int	i;
	int	pos;
	int	arr;

	i = -1;
	pos = img->player_x;
	arr = img->player_y;
	while (++i < 25000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->exit_1,
			(pos * 64), (arr * 64));
	i = -1;
	put_win_animation(i, data, img);
	while (++i < 25000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->exit, (pos
				* 64), (arr * 64));
	ft_printf("You WON, well played <(*-*)>\n");
	(void)map;
}

void	put_win_animation(int i, t_data *data, t_img *img)
{
	int	pos;
	int	arr;

	pos = img->player_x;
	arr = img->player_y;
	while (++i < 25000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->exit_2,
			(pos * 64), (arr * 64));
	while (++i < 50000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->exit_3,
			(pos * 64), (arr * 64));
	while (++i < 75000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->exit_4,
			(pos * 64), (arr * 64));
	while (++i < 100000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->exit_5,
			(pos * 64), (arr * 64));
	while (++i < 125000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->exit_6,
			(pos * 64), (arr * 64));
	while (++i < 150000)
		mlx_put_image_to_window(data->mlx_display, data->window, img->exit_7,
			(pos * 64), (arr * 64));
}

void	put_steps_clean(t_data *data)
{
	char	*steps;

	steps = ft_itoa(data->steps + 1);
	mlx_put_image_to_window(data->mlx_display, data->window,
		data->map_struct->crate_steps, (1 * 64), (0 * 64));
	mlx_string_put(data->mlx_display, data->window, 86, 50, 0xF57B3E, steps);
	free(steps);
}
