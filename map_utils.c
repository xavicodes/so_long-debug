/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:14:43 by xaviermonte       #+#    #+#             */
/*   Updated: 2025/01/13 19:17:12 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void check_if_map_is_playable(t_data *vars)
{
        t_flood flood;
        char **map_copy;

        map_copy = vars->game.map;
        if(!map_copy)
                return;
        flood.rows = vars->game.rows;
        flood.column = vars->game.column;
        flood.colectables = count_colletables(vars);
        flood.exit = 0;
        if(vars->player.x == -1 || vars->player.y == -1)
                error_text();
        
        floodfill(&flood,vars->player.x,vars->player.y);
        if(flood.colectables != 0 || flood.exit != 1)
        {
                free_map(map_copy,vars);
                error_text();
        }
        free_map(map_copy,vars);
        
}
void check_map(t_data *vars)
{
        int i;

        i = 0;
        while(i < vars->game.column)
        {
                if(strlen_no_n(vars->game.map[i]) != vars->game.rows)
                        error_text();
                else
        i++;
        }
}

void check_walls(t_data *vars)
{
        int i;

        i = 0;
        while(i < vars->game.column)
        {
                if(vars->game.map[0][i] != '1' || vars->game.map[0][i] - 1 != '1')
                        error_text();
        i++;
        }
        i = 0;
        while(i < vars->game.rows)
        {
                if(vars->game.map[i][0] != '1' || vars->game.map[i][0] - 1 != '1')
                        error_text();
        i++;
        }
}

void check_player_position(t_data *vars)
{
        int i;
        int j;
        
        i = 1;
        j = 1;
        while(vars->game.column > j - 1)
        {
                while(vars->game.rows > i - 1)
                {
                        if(vars->game.map[j][i] == 'P')
                        {
                                vars->player.x = i;
                                vars->player.y = j;
                                return;
                        }
                i++;
                }
        j++;
        }
}

void check_conditions(t_data *vars)
{
        int p_count;
        int c_count;
        int e_count;

        count_elements(vars, &p_count, &c_count, &e_count);
        if(p_count != 1 || c_count <= 0 || e_count != 1)
                error_text();
        
        
}
void init_variables(t_data *vars)
{
        vars->player.x = -1;
        vars->player.y = -1;
        vars->player.moves = 0;
        vars->player.t_colectables = count_colletables(vars);
        
        
}

void check_letters(t_data *vars)
{
        init_variables(vars);
        check_player_position(vars);
        check_conditions(vars);
        check_if_map_is_playable(vars)  ;
}
