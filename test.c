#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

# define WINDOW_WIDTH  600
# define WINDOW_HEIGHT 400
# define MLX_ERROR 1



typedef struct s_data
{
    void    *mlx_display;
    void    *window;
    int teste;
}   t_data;


int handle_no_event(t_data *data)
{
    data->teste = 0;
    return (0);
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

    void *img;
    char *rel_path = "./imgs/pikachu_64.xpm";
    int     img_width;
    int     img_height;

    data.mlx_display = mlx_init();
    if (data.mlx_display == NULL)
        return (MLX_ERROR);
    data.window = mlx_new_window(data.mlx_display, WINDOW_WIDTH, WINDOW_HEIGHT, "Crash Bandicoot 2D experience");
    if (data.window == NULL)
    {
        free (data.window);
        return (MLX_ERROR);
    }
    img = mlx_xpm_file_to_image(data.mlx_display, rel_path, &img_width, &img_height);
    mlx_loop_hook(data.mlx_display, &handle_no_event, &data);
    mlx_hook(data.window, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_hook(data.window, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
    mlx_loop(data.mlx_display);

    return (0);
    
}   