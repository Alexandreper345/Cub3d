/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:02:57 by erocha-l          #+#    #+#             */
/*   Updated: 2025/10/15 15:37:44 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
static void create_texture(t_vars *vars, t_texture *tex, char *path)
{
    t_map   *map;
    
    map = &vars->map;
    tex->img_ptr = mlx_xpm_file_to_image(vars->mlx, path, &map->tex_width, &map->tex_height);
    if (tex->img_ptr == NULL)
    {
        printf("erro ao carregar textura\n"); //mudar talvez
        exit(1);
    }
    tex->addr = mlx_get_data_addr(
        tex->img_ptr,
        &tex->bpp,
        &tex->line_len,
        &tex->endian);
    tex->width = map->tex_width;
    tex->height = map->tex_height;
}

static  void    convert_textures_to_img(t_vars *vars)
{
    t_map   *map;

    map = &vars->map;
    map->tex_width = 256;
    map->tex_height = 256;
    create_texture(vars, &map->NO, map->NO_path);
    create_texture(vars, &map->EA, map->EA_path);
    create_texture(vars, &map->SO, map->SO_path);
    create_texture(vars, &map->WE, map->WE_path);
}


/*static void render_line(t_vars *vars, int y_axis, char *line)
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
    
}*/

void game_settings(t_vars *vars)
{
    convert_textures_to_img(vars);
    mlx_hook(vars->win, 2, 1L<<0, escape, vars); // create enum
    mlx_hook(vars->win, 17, 1L<<19, x_button, vars); // create enum
    //render_map(vars);
}
