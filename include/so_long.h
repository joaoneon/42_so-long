/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:43:36 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/07/26 19:48:02 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>
#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>

# define WINDOW_WIDTH  832
# define WINDOW_HEIGHT 320
# define MLX_ERROR 1
#define PLAYER "./imgs/player_64.xpm"
#define FLOOR "./imgs/floor_64.xpm"
#define WALL "./imgs/wall_64.xpm"
#define EXIT "./imgs/exit_64.xpm"
#define COLLECTABLE "./imgs/collectable_64.xpm"
#define ENEMY "./imgs/enemy_64.xpm"


typedef struct s_map
{
    char **map;
    char **map_cpy;
    int     player_x;
    int     player_y;
    int     exit_x;
    int     exit_y;
    int     map_x;
    int     map_y;
    int     collectables_score;
}   t_map;

typedef struct s_img
{
    void *player;
    void *floor;
    void *wall;
    void *collectable;
    void *enemy;
    void *exit;
    int     x;
    int     y;
    int     img_width;
    int     img_height;
    int     back_x;
    int     back_y;
    int     player_x;
    int     player_y;
}   t_img;

typedef struct s_data
{
    void    *mlx_display;
    void    *window;
    t_img   *images_struct;
    t_map   *map_struct;
    int teste;
}   t_data;

int check_file_name(char *str);
int	handle_map(t_data *data, char *map_name);
int	put_map(t_data *data, t_img *img, t_map *map);
int map_check_walls(t_map *map);
int map_check(t_map *map, t_data *data);
int handle_no_event(t_data *data);
void handle_movement(int keysym, t_data *data, t_img *img, t_map *map);
int handle_keypress(int keysym, t_data *data);
int   handle_keyrelease(int keysym, t_data *data);
void free_for_finish(t_data *data);
int map_check_players(t_map *map);
void load_images(t_data *data, t_img *img, t_map *map);
void put_player_enemy(char c, t_data *data, t_img *img, int pos, int arr);
char	*ft_strdup(char *s);
int check_colision(int keysym, t_data *data, t_img *img, t_map *map);
void copy_map_string(char **str, t_data *data);

#endif