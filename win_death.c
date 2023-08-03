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
