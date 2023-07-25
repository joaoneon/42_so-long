#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

# define WINDOW_WIDTH  640
# define WINDOW_HEIGHT 380
# define MLX_ERROR 1
#define PLAYER "./imgs/player_64.xpm"
#define FLOOR "./imgs/floor_64.xpm"

typedef struct s_img
{
    void *player;
    void *floor;
    int     x;
    int     y;
    int     img_width;
    int     img_height;
    int     back_x;
    int     back_y;
}   t_img;

typedef struct s_data
{
    void    *mlx_display;
    void    *window;
    t_img   *images_struc;
    int teste;
}   t_data;


int handle_no_event(t_data *data)
{
    data->teste = 0;
    return (0);
}

void handle_movement(int keysym, t_data *data)
{
    if ((keysym == 119 || keysym == XK_Up) && (data->images_struc->y >= 64))
    {
            data->images_struc->back_y = data->images_struc->y;
            data->images_struc->y -= 64;
            mlx_put_image_to_window(data->mlx_display, data->window, data->images_struc->floor, data->images_struc->x, data->images_struc->back_y);
            mlx_put_image_to_window(data->mlx_display, data->window, data->images_struc->player, data->images_struc->x, data->images_struc->y);
            printf("Pressed key: %d\n", keysym);
    }
     if ((keysym == 97 || keysym == XK_Left) && (data->images_struc->x >= 64))
    {
        data->images_struc->back_x = data->images_struc->x;
        data->images_struc->x -= 64;
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struc->floor, data->images_struc->back_x, data->images_struc->y);
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struc->player, data->images_struc->x, data->images_struc->y);
        printf("Pressed key: %d\n", keysym);
    }
     if ((keysym == 115 || keysym == XK_Down)&& (data->images_struc->y <= WINDOW_HEIGHT - 64))
    {
        data->images_struc->back_y = data->images_struc->y;
        data->images_struc->y += 64;
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struc->floor, data->images_struc->x, data->images_struc->back_y);
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struc->player, data->images_struc->x, data->images_struc->y);
        printf("Pressed key: %d\n", keysym);
    }
     if ((keysym == 100 || keysym == XK_Right) && (data->images_struc->x < WINDOW_WIDTH - 64)) 
    {
        data->images_struc->back_x = data->images_struc->x;
        data->images_struc->x += 64;
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struc->floor, data->images_struc->back_x, data->images_struc->y);
        mlx_put_image_to_window(data->mlx_display, data->window, data->images_struc->player, data->images_struc->x, data->images_struc->y);
        printf("Pressed key: %d\n", keysym);
    }
}

int handle_keypress(int keysym, t_data *data)
{   
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_display, data->window);
        mlx_destroy_display(data->mlx_display);
        free(data->mlx_display);
        printf("Pressed key: %d\n", keysym);
        exit(0);
    }
    handle_movement(keysym, data);    
    return (0);
}
int   handle_keyrelease(int keysym, t_data *data)
{

    (void) *data;
    printf("Released key: %d\n", keysym);
    return (0);
}



int main(void)
{
    t_data data;

    t_img img;
    data.images_struc = &img;

    img.x = 0;
    img.y = 0;
    data.mlx_display = mlx_init();
    if (data.mlx_display == NULL)
        return (MLX_ERROR);
    data.window = mlx_new_window(data.mlx_display, WINDOW_WIDTH, WINDOW_HEIGHT, "Crash Bandicoot 2D experience");
    if (data.window == NULL)
    {
        free (data.window);
        return (MLX_ERROR);
    }

    img.player = mlx_xpm_file_to_image(data.mlx_display, PLAYER, &img.img_height, &img.img_height);
    img.floor = mlx_xpm_file_to_image(data.mlx_display, FLOOR, &img.img_height, &img.img_height);
    mlx_put_image_to_window(data.mlx_display, data.window, img.player, img.x, img.y);
    mlx_loop_hook(data.mlx_display, &handle_no_event, &data);
    mlx_hook(data.window, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_hook(data.window, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
    mlx_loop(data.mlx_display);

    return (0);
    
}   