/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:34:34 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/03 17:50:06 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_map(t_data *data, char *map_name)
{
	int		fd;
	char	*str;
	int		index;

	fd = open(map_name, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
	{
		free(str);
		ft_printf("Map has nothing inside\n");
		exit (1);
	}
	handle_map2(data, fd, str);
	close(fd);
	data->map_struct->map = ft_calloc(sizeof(char *),
			(data->map_struct->map_y + 1));
	index = -1;
	fd = open(map_name, O_RDONLY);
	while (++index < data->map_struct->map_y)
		data->map_struct->map[index] = get_next_line(fd);
	close(fd);
	data->map_struct->map[index] = NULL;
	copy_map_string(data->map_struct->map, data);
	return (1);
}

void	handle_map2(t_data *data, int fd, char *str)
{
	int	signal;

	signal = 0;
	data->map_struct->map_x = (int)ft_strlen(str);
	data->map_struct->map_y = 1;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		data->map_struct->map_y++;
	}
	free(str);
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
