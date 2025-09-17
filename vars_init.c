/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-17 22:08:42 by erocha-l          #+#    #+#             */
/*   Updated: 2025-09-17 22:08:42 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

static void    init_map(t_map *map)
{
    map->map = NULL;
    map->map_fd = 0;
    map->width = 0;
    map->height = 0;
    map->ceiling_color = NULL;
    map->floor_color = NULL;
    map->player = NULL; 
}

void    init_vars(t_vars *vars)
{
    vars->height = 0;
    vars->width = 0;
    vars->mlx = NULL;
    vars->win = NULL;
    vars->game = NULL;
    vars->player = NULL;
    //init_map(vars->map);
}
