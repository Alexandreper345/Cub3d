/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:24:51 by erocha-l          #+#    #+#             */
/*   Updated: 2025/10/12 17:32:10 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char *determinate_texture(t_camera *cam, t_vars *vars, t_vars *map)
{
    if (cam->side == 0)
    {
        if (cam->rayDirX < 0)
            return (map->WE)
        else 
            return (map->EA)
    }
    else
    {
        if (cam->rayDirY < 0)
            return (map->NO)
        else
            return (map->SO) 
    }
}
