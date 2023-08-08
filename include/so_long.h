/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-a <jpedro-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:43:36 by jpedro-a          #+#    #+#             */
/*   Updated: 2023/08/03 17:11:28 by jpedro-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define MLX_ERROR 1
# define PLAYER "./imgs/player_d_64.xpm"
# define PLAYER_U "./imgs/player_u_64.xpm"
# define PLAYER_L "./imgs/player_l_64.xpm"
# define PLAYER_R "./imgs/player_r_64.xpm"
# define FLOOR "./imgs/floor_64.xpm"
# define WALL "./imgs/wall_64.xpm"
# define EXIT "./imgs/exit_64.xpm"
# define COLLECTABLE "./imgs/collectable_64.xpm"
# define ENEMY "./imgs/enemy_64.xpm"
# define DEATH_1 "./imgs/death_1.xpm"
# define DEATH_2 "./imgs/death_2.xpm"
# define DEATH_3 "./imgs/death_3.xpm"
# define DEATH_4 "./imgs/death_4.xpm"
# define DEATH_5 "./imgs/death_5.xpm"
# define DEATH_6 "./imgs/death_6.xpm"
# define EXIT_1 "./imgs/exit_1.xpm"
# define EXIT_2 "./imgs/exit_2.xpm"
# define EXIT_3 "./imgs/exit_3.xpm"
# define EXIT_4 "./imgs/exit_4.xpm"
# define EXIT_5 "./imgs/exit_5.xpm"
# define EXIT_6 "./imgs/exit_6.xpm"
# define EXIT_7 "./imgs/exit_7.xpm"
# define CRATE "./imgs/crate_steps.xpm"

typedef struct s_map
{
	char	**map;
	char	**map_cpy;
	void	*crate_steps;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		map_x;
	int		map_y;
	int		collectables_score;
	int		collectables_amount;
	int		exit_signal;
}			t_map;

typedef struct s_img
{
	void	*player;
	void	*player_u;
	void	*player_l;
	void	*player_r;
	void	*floor;
	void	*wall;
	void	*collectable;
	void	*enemy;
	void	*exit;
	void	*death_1;
	void	*death_2;
	void	*death_3;
	void	*death_4;
	void	*death_5;
	void	*death_6;
	void	*exit_1;
	void	*exit_2;
	void	*exit_3;
	void	*exit_4;
	void	*exit_5;
	void	*exit_6;
	void	*exit_7;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	int		back_x;
	int		back_y;
	int		player_x;
	int		player_y;
}			t_img;

typedef struct s_data
{
	void	*mlx_display;
	void	*window;
	t_img	*images_struct;
	t_map	*map_struct;
	int		render_signal;
	int		steps;
}			t_data;

int			program_flux(t_data *data, t_img *img, t_map *map, char *av);
int			check_file_name(char *str);
int			handle_map(t_data *data, char *map_name);
int			put_map(t_data *data, t_map *map);
int			map_check_walls(t_map *map);
int			map_check(t_map *map, t_data *data);
int			handle_no_event(t_data *data);
void		handle_movement(int keysym, t_data *data, t_img *img, t_map *map);
int			handle_keypress(int keysym, t_data *data);
int			handle_keyrelease(int keysym, t_data *data);
void		free_for_finish(t_data *data);
int			map_check_players(t_map *map);
void		load_images(t_data *data, t_img *img, t_map *map);
void		put_player_enemy(char c, t_data *data, int pos, int arr);
char		*ft_strdup(char *s);
int			check_colision(int keysym, t_data *data, t_img *img, t_map *map);
void		copy_map_string(char **str, t_data *data);
void		death_animation(t_img *img, t_map *map, t_data *data);
void		check_collectable(t_img *img, t_map *map, char **mapper,
				t_data *data);
void		win_animation(t_img *img, t_map *map, t_data *data);
void		ft_free_ptr(void **ptr);
char		*ft_itoa(int n);
void		handle_map2(t_data *data, int fd, char *str);
void		put_map_aux(t_data *data, char c, int pos, int arr);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
void		check_exit(t_map *map, t_img *img, char **mapper, t_data *data);
int			check_colision_right(t_data *data, t_map *map, int x, int y);
int			check_colision_down(t_data *data, t_map *map, int x, int y);
int			check_colision_left(t_data *data, t_map *map, int x, int y);
int			check_colision_up(t_data *data, t_map *map, int x, int y);
void		flood_fill(t_map *map, t_data *data, int x, int y);
int			map_check_exit(t_map *map);
void		map_check_p2(t_map *map, t_data *data);
int			map_check_collectables(t_map *map);
int			map_flood_collectables(t_map *map);
void		free_maps(t_data *data);
void		free_images(t_data *data);
void		get_player_pos(t_data *data);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memset(void *s, int c, size_t x);
void		free_map(t_data *data);
int			handle_x_press(t_data *data);
int			map_check_characters(t_map *map);
void		load_images_2(t_data *data, t_img *img);
void		free_images_2(t_data *data);
void		free_images_3(t_data *data);
void		put_death_animation(int i, t_data *data, t_img *img);
void		put_win_animation(int i, t_data *data, t_img *img);
void		put_steps_clean(t_data *data);
int			check_player_to_floor(int x, int y, char **mapper, t_data *data);

#endif