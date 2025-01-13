#include "so_long.h"

void create_window(t_data *vars)

{
        mlx_get_screen_size(vars->mlx, &vars->window_height, &vars->window_width);
        if(vars->window_height < vars->game.map_hight || vars->window_width < vars->game.map_width)
                error();
        vars->mlx_window = mlx_new_window(vars->mlx,vars->game.map_width ,vars->game.map_hight, "So_Long");

        vars->mlx_img = mlx_new_image(vars->mlx ,vars->game.map_width, vars->game.map_hight);
        vars->mlx_adress = mlx_get_data_addr(vars->mlx_img, &vars->bits_per_pixel , &vars->size_line, &vars->endian);
}

void store_sprites(t_data *vars)
{
        mlx_xpm_file_to_image(vars->mlx, "sprites/player.xpm",&vars->sprites.img_width, &vars->sprites.img_height);
        mlx_xpm_file_to_image(vars->mlx,"sprites/collectable.xpm", &vars->sprites.img_width, &vars->sprites.img_height);
        mlx_xpm_file_to_image(vars->mlx,"sprites/wall.xpm", &vars->sprites.img_width, &vars->sprites.img_height);
        mlx_xpm_file_to_image(vars->mlx,"sprites/floor.xpm", &vars->sprites.img_width, &vars->sprites.img_height);
        mlx_xpm_file_to_image(vars->mlx,"sprites/exit.xpm", &vars->sprites.img_width, &vars->sprites.img_height);

}