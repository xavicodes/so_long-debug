/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:14:30 by xaviermonte       #+#    #+#             */
/*   Updated: 2025/01/13 19:23:57 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void create_window(t_data *vars)

{
        mlx_get_screen_size(vars->mlx, &vars->window_height, &vars->window_width);
        if(vars->window_height < vars->game.map_hight || vars->window_width < vars->game.map_width)
                error_text();
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

void clean_map(t_data *vars)
{
        if(vars->game.map)
        {
                free_map(vars->game.map,vars->game.rows);
                vars->game.map = NULL;
        }
}
void destroy_sprites(t_data *vars)
{
        mlx_destroy_image(vars->mlx,vars->sprites.collectable);
        mlx_destroy_image(vars->mlx,vars->sprites.player);
        mlx_destroy_image(vars->mlx,vars->sprites.exit);
        mlx_destroy_image(vars->mlx,vars->sprites.floor);
        mlx_destroy_image(vars->mlx,vars->sprites.walls);
        mlx_destroy_window(vars->mlx,vars->mlx_window);
        mlx_destroy_display(vars->mlx);
        mlx_loop_end(vars->mlx);
        clean_map(vars);
}