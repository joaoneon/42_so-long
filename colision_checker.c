#include "so_long.h"

char	*ft_strdup(char *s)
{
	char	*s2;
	int		len;
	int		temp;

	len = (int)ft_strlen(s);
	temp = len;
	s2 = malloc((len ) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (len-- > 0)
		*s2++ = *s++;
	*s2 = '\0';
	s2 -= temp;
	return (s2);
}

void copy_map_string(char **str, t_data *data)
{
    // int max_y;
    // int lines;

    // max_y = data->map_struct->map_y;
    // lines = 0;
    // while (lines < max_y)
    // {
    //     printf("%s", str[lines]);
    //     ft_printf("counter %i", ft_strlen(str[lines]));
    //     data->map_struct->map_cpy[lines] = ft_strdup(str[lines]);
    //     printf("%s", data->map_struct->map_cpy[lines]);
    //     lines++;
    // }

    (void)str;
    (void)data;

}

void    check_collectable(t_img *img, t_map *map, char **mapper)
{
    int x;
    int y;
    x = img->player_x;
    y = img->player_y;

    if (mapper[y][x] == 'C')
    {
        map->collectables_score += 1;
        mapper[y][x] = '0';
        ft_printf("score: %i\n", map->collectables_score);
    }

}

int check_colision(int keysym, t_data *data, t_img *img, t_map *map)
{
    // get_player_pos(map, img);
    int x;
    int y;
    (void)data;
    // (void)img;
    // (void)map;
    char **mapper;
    mapper = map->map;
    // XK_Up || 119
    // 97 || XK_Left
    // 115 || XK_Down
    // 100 || XK_Right
    x = img->player_x;
    y = img->player_y;

    if (keysym == 119 || keysym == XK_Up)
    {
        if (mapper[y - 1][x] == '1')
            return (0);           
        else
        {
            img->player_y -=1;
            check_collectable(img, map, mapper);
            return (1);
        }        
    } 
    if (keysym == 115 || keysym == XK_Down)
    {
        if (mapper[y + 1][x] == '1')
            return (0);
        else
        {
            img->player_y +=1;
            check_collectable(img, map, mapper);
            return (1);
        }
    }
    if (keysym == 97 || keysym == XK_Left)
    {
        if (mapper[y][x - 1] == '1')
            return (0);
        else
        {
            img->player_x -=1;
            check_collectable(img, map, mapper);
            return (1);
        }
    }
    if (keysym == 100 || keysym == XK_Right)
    {
        if (mapper[y][x + 1] == '1')
            return (0);
        else
        {
            img->player_x +=1;
            check_collectable(img, map, mapper);
            return (1);
        }
    }
    return (0);
}