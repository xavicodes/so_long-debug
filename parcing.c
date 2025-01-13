#include "so_long.h"

void error()
{
        write(1,"error\n",7);
        exit(1);
}

int     verify_map_name(char **av)
{
        int i;

        i = 0;
        while(av[1][i] != '.')
        i++;
        i++;
        if(av[1][i] == 'b')
        i++;
        else
        return(1);
        if(av[1][i] == 'e')
        i++;
        else
        return(1);
        if(av[1][i] == 'r')
        i++;
        else
        return(1);
        return(0);

}
int create_matrix(char *file, t_data *vars)
{
        int i;
        int fd;
        char *line;

        i = 0;
        vars->game.map = malloc(vars->game.rows *sizeof(char *));
        if(!vars->game.map)
        {
                free(vars->game.map);
                return(1);
        }
        fd = open(file, O_RDONLY);
        line = get_next_line(fd);
        while(line)
        {
                vars->game.map[i] = line;
                i++;
                line = get_next_line(fd);
        }
        close(fd);
        check_walls(vars);
        check_map(vars);
        check_letters(vars);
        vars->game.map_width = vars->game.column * 32;
        vars->game.map_hight = vars->game.rows * 32;
        return(0);
}
int read_map(char *file, t_data *vars)
{
        int fd;
        char *line;

        fd = open(file, O_RDONLY);
        line = get_next_line(fd);
        if(!line)
        {
                free(line);
                return(1);
        }
        vars->game.column = 0;
        while(line[vars->game.column] != '\n' || file[vars->game.column] != '\0')
        vars->game.column++;
        while(line)
        {
                vars->game.rows++;
                free(line);
                line = get_next_line(fd);
        }
        close(fd);
        create_matrix(file, vars);
        return(0);
}