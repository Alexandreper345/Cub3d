/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:02:57 by erocha-l          #+#    #+#             */
/*   Updated: 2025/09/25 20:07:15 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static  convert_textures_to_img(t_vars *vars)
{
    t_map map;
    
    map = vars->map;
    map->width = 256;
    map->height = 256;
    map->NORTH = mlx_xpm_file_to_image(vars->mlx, map->NO_path, map->)
}

void gameplay(t_vars *vars)
{
    convert_textures_to_img(vars);
    mlx_hook(vars->win, 2, 1L<<0, escape, vars); // create enum
    mlx_hook(vars->win, 17, 1L<<19, x_button, vars); // create enum
}
