/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:02:57 by erocha-l          #+#    #+#             */
/*   Updated: 2025/10/12 16:49:30 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static  void convert_textures_to_img(t_vars *vars)
{
    t_map   *map;

    map = &vars->map;
    map->width = 256;
    map->height = 256;
    map->NO = mlx_xpm_file_to_image(vars->mlx, map->NO_path, &map->width, &map->height);
    map->EA = mlx_xpm_file_to_image(vars->mlx, map->EA_path, &map->width, &map->height);
    map->SO = mlx_xpm_file_to_image(vars->mlx, map->SO_path, &map->width, &map->height);
    map->WE = mlx_xpm_file_to_image(vars->mlx, map->WE_path, &map->width, &map->height);
}


static void render_line(t_vars *vars, int y_axis, char *line)
{
    t_map   *map;
    int     x_axis;
    int     i;
    
    map = &vars->map;
    x_axis = 0;
    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        if (i % 2 == 0)
            mlx_put_image_to_window(vars->mlx, vars->win, map->EA, x_axis, y_axis);
        else
            mlx_put_image_to_window(vars->mlx, vars->win, map->NO, x_axis, y_axis);
        x_axis = x_axis + 256;
        i++;
        printf("loppei 2\n");
    }
}

static void render_map(t_vars *vars)
{
    t_map   *map;
    char    **grid;
    int     i;
    int     y_axis;

    i = 0;
    map = &vars->map;
    grid = map->map;
    y_axis = 0;
    while (grid[i] != NULL)
    {
        render_line(vars, y_axis, grid[i]);
        i++;
        y_axis = y_axis + 256;
        printf("loppei 1\n");
    }
    
}

void render_wall(t_vars *vars)

void game_settings(t_vars *vars)
{
    convert_textures_to_img(vars);
    mlx_hook(vars->win, 2, 1L<<0, escape, vars); // create enum
    mlx_hook(vars->win, 17, 1L<<19, x_button, vars); // create enum
    //render_map(vars);
}
