#include "so_long.h"
void draw_sprite(t_data *vars,void *sprite, int x, int y)
{
        mlx_put_image_to_window(vars->mlx,vars->mlx_window,sprite, x * 32, y * 32);
}

void draw_block(t_data *vars, int x, int y)
{
        if(vars->game.map[y][x] == 'P')
                draw_sprite(vars,vars->sprites.player,x,y);
        if(vars->game.map[y][x] == '1')
                draw_sprite(vars,vars->sprites.walls,x,y);
        if(vars->game.map[y][x] == '0')
                draw_sprite(vars,vars->sprites.floor,x,y);
        if(vars->game.map[y][x] == 'C')
                draw_sprite(vars,vars->sprites.collectable,x,y);
        if(vars->game.map[y][x] == 'E')
                draw_sprite(vars,vars->sprites.exit,x,y);
}

void draw_game(t_data *vars)
{
        int x;
        int y;
        
        y = 0;
        x = 0;
        while(vars->game.map[y][x] != '\0' || vars->game.map[y][x] != '\n')
        {
                x = 0;
                while(vars->game.map[y][x] != '\0' || vars->game.map[y][x] != '\n')
                {
                        draw_block(vars,x,y);
                        x++;
                }
        y++;
        }
}