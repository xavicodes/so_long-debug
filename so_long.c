/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:38:30 by xaviermonte       #+#    #+#             */
/*   Updated: 2025/01/13 19:22:12 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int ac, char **av)
{
        t_data vars;

        vars.game.map = NULL;
        if(ac == 2)
                {
                        if(!verify_map_name(av))
                        read_map(av[1],&vars);
                }
                else
                        return(1);
        vars.mlx = mlx_init();
         create_window(&vars);
        store_sprites(&vars);
        draw_game(&vars);
        game_hooks(&vars);
        mlx_loop(&vars.mlx);
        mlx_destroy_sprites(vars);
        free(vars.mlx);
        return(0);
} 
