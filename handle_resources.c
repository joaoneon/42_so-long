/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_resources.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:48:35 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/07/27 16:53:52 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_no_event(t_data *data)
{
    data->teste = 0;
    return (0);
}



void handle_movement(int keysym, t_data *data, t_img *img, t_map *map)
{
    // check_colision(keysym, data, img, map);
    ft_printf("Pressed key: %d\n", keysym);
    if ((keysym == 119 || keysym == XK_Up) && (check_colision(keysym, data, img, map)))
    {
            data->images_struct->back_y = data->images_struct->y;
            data->images_struct->y -= 64;
            mlx_put_image_to_window(data->mlx_display, data->window, data->images_struct->floor, data->images_struct->x, data->images_struct->back_y);
            mlx_put_image_to_window(data->mlx_display, data->window, data->images_struct->player, data->images_struct->x, data->images_struct->y);
    }
     if ((keysym == 97 || keysym == XK_Left) && (check_colision(keysym, data, img, map)))
    {
        data->images_struct->back_x = data->images_struct->x;
        data->images_struct->x -= 64;
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struct->floor, data->images_struct->back_x, data->images_struct->y);
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struct->player, data->images_struct->x, data->images_struct->y);
        // ft_printf("Pressed key: %d\n", keysym);
    }
     if ((keysym == 115 || keysym == XK_Down) && (check_colision(keysym, data, img, map)))
    {
        data->images_struct->back_y = data->images_struct->y;
        data->images_struct->y += 64;
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struct->floor, data->images_struct->x, data->images_struct->back_y);
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struct->player, data->images_struct->x, data->images_struct->y);
        // ft_printf("Pressed key: %d\n", keysym);
    }
     if ((keysym == 100 || keysym == XK_Right) && (check_colision(keysym, data, img, map))) 
    {
        data->images_struct->back_x = data->images_struct->x;
        data->images_struct->x += 64;
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struct->floor, data->images_struct->back_x, data->images_struct->y);
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struct->player, data->images_struct->x, data->images_struct->y);
        // ft_printf("Pressed key: %d\n", keysym);
    }
}

int handle_keypress(int keysym, t_data *data)
{   
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_display, data->window);
        mlx_destroy_display(data->mlx_display);
        free(data->mlx_display);
        ft_printf("Pressed key: %d\n", keysym);
        exit(0);
    }
    t_map *map;
    t_img *img;

    map = data->map_struct;
    img = data->images_struct;
    handle_movement(keysym, data, img, map);    
    return (0);
}
int   handle_keyrelease(int keysym, t_data *data)
{

    (void) *data;
    ft_printf("Released key: %d\n", keysym);
    return (0);
}
