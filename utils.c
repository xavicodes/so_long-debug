/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:15:02 by xaviermonte       #+#    #+#             */
/*   Updated: 2025/01/13 19:17:12 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void free_map(char **map,int rows)
{
        int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
int strlen_no_n(char *map)
{
        int i;

        i = 0;
        while(map[i] != '\n' || map[i] != '\0')
        i++;
        return(i);
}
void floodfill(t_flood *flood,int x, int y)
{
        int exit;

        exit = 0;

                if(x < 0 || y < 0 )
                        return;
                if(flood->map_copy[y][x] == '1' )
                        return;
                else if(flood->map_copy[y][x] == 'C')
                {
                        flood->colectables++;
                        flood->map_copy[y][x] = 'F';
                }
                else if(flood->map_copy[y][x] == 'E')
                {
                        flood->exit++;
                        flood->map_copy[y][x] = 'F';
                }
                else if(flood->map_copy[y][x] == '0')
                        flood->map_copy[y][x] = 'F';

        floodfill(flood,x+1,y);
        floodfill(flood,x-1,y);
        floodfill(flood,x,y+1);
        floodfill(flood,x,y-1);
}


void count_elements(t_data *vars,int *p_count, int *c_count, int *e_count)
{
        int i;
        int j;

        i = 0;
        *p_count = 0;
        *c_count = 0;
        *e_count = 0;    
        
        while(vars->game.rows > i)
        {
                j = 0;
                while(j < vars->game.column)
                {
                if(vars->game.map[i][j] == 'C' )
                        (*c_count)++;
                else if(vars->game.map[i][j] == 'P')
                        (*p_count)++;
                else if(vars->game.map[i][j] == 'E')
                        (*e_count)++;
                else if(vars->game.map[i][j] != '1' || vars->game.map[i][j] != '0')
                        error_text();
                j++;
                }
        i++;
        }
}
int count_colletables(t_data *vars)
{

        int i;
        int j;
        int count;

        count = 0;
        i = 0;
        j = 0;
        while(vars->game.map[i][j] != '\0' || vars->game.map[i][j] != '\n')
        {
                j = 0;
                while(vars->game.map[i][j] != '\0' || vars->game.map[i][j] != '\n')
                {
                        if(vars->game.map[i][j] == 'C')
                                count++;
                j++;
                }
        i++;
        }
        return(count);
}