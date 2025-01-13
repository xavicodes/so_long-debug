#include "so_long.h"
void count_moves(t_data *vars)
{
        char *print_moves;

        print_moves = ft_itoa(vars->player.moves);
        if(!print_moves)
                error();

        
        mlx_string_put(vars->mlx,vars->mlx_window,5 , 10,0xFFFFFF, "moves");
        mlx_string_put(vars->mlx, vars->mlx_window, 50, 10,0xFFFFFF, print_moves);
        ft_printf("movimentos :%s",print_moves);

}
void move_player(t_data *vars, int x_dif, int y_dif)
{
        int new_x;
        int new_y;
        
        new_x = vars->player.x + x_dif;
        new_y = vars->player.y + y_dif;
        if(vars->game.map[new_y][new_x] != '1')
        {
                if(vars->game.map[new_y][new_x] == 'C')
                {
                        vars->player.t_colectables--;
                }
                if(vars->game.map[new_y][new_x] == 'E')
                {
                        if(vars->player.t_colectables == 0)
                                close_window(vars);
                        return;
                }
                vars->game.map[vars->player.y][vars->player.x] = 0;
                vars->game.map[new_y][new_x] = 'P';
                vars->player.y = new_y;
                vars->player.x = new_x;
                vars->player.moves++;
                count_moves(vars);
        }
}

int close_window(t_data *vars)
{
mlx_loop_end(vars->mlx);
return(0);
}
int key_hooks(t_data *vars, int key)
{
        if(key == ESC)
                close_window(vars);
        if(key == LEFT)
                move_player(vars, -1 , 0);
        if(key == RIGHT)
                move_player(vars, 1, 0);
        if(key == UP)
                move_player(vars, 0, -1);
        if(key == DOWN)
                move_player(vars, 0 , 1);
return (0);
}


void game_hooks(t_data *vars)
{
        mlx_hook(vars->mlx_window,17, 0,close_window, vars);
        mlx_key_hook(vars->mlx_window, key_hooks, vars);        
}