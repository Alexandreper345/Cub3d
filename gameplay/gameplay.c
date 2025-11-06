/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:32:57 by erocha-l          #+#    #+#             */
/*   Updated: 2025/11/06 19:53:57 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int cal_floor_and_ceilling(t_map *map, t_camera *cam, t_vars *vars)
{
        while (cam->y < vars->height / 2)
    {
        map->x_ceil = 0;
        while (map->x_ceil < vars->width)
        {
            my_pixel_put_to_buffer(&vars->buffer, map->x_ceil, cam->y, map->Ceiling_color);
            (map->x_ceil)++;
        }
        (cam->y)++;
    }
    while (cam->y < vars->height)
    {
        map->x_floor = 0;
        while (map->x_floor < vars->width)
        {
            my_pixel_put_to_buffer(&vars->buffer, map->x_floor, cam->y, map->Floor_color);
            (map->x_floor)++;
        }
        (cam->y)++;
    }
}


int gameplay(t_vars *vars)
{
    t_map       *map;
    t_camera    *cam;
    t_player    *player;
    t_texture   *tex;
    
    map = &vars->map;
    cam = &vars->camera;
    player = &vars->player;
    cam->height = 720;
    cam->x = 0;
    cam->y = 0;
    cal_floor_and_ceilling(map, cam, vars);
    while(cam->x < vars->width)
    {
        dda(map, cam, player, vars);
        tex = determinate_texture(cam, vars, map);
        if (cam->side == 0)
            cam->perpWallDist = (cam->sideDistX - cam->deltaDistX);
        else
            cam->perpWallDist = (cam->sideDistY - cam->deltaDistY);
        cam->lineHeight = (int)(cam->height / cam->perpWallDist);
        cam->drawStart = -cam->lineHeight / 2 + cam->height / 2;
        if (cam->drawStart < 0)
            cam->drawStart = 0;
        cam->drawEnd = cam->lineHeight / 2 + cam->height / 2;
        if (cam->drawEnd >= cam->height)
            cam->drawEnd = cam->height - 1;
        if (cam->side == 0)
            cam->wallX = player->posY + cam->perpWallDist * cam->rayDirY;
        else
            cam->wallX = player->posX + cam->perpWallDist * cam->rayDirX;
        cam->wallX -= floor(cam->wallX);
        cam->texX = (int)(cam->wallX * (double)tex->width);
        if ((cam->side == 0 && cam->rayDirX > 0) || (cam->side == 1 && cam->rayDirY < 0))
            cam->texX = tex->width - cam->texX - 1;
        cam->step = 1.0 * tex->height / cam->lineHeight;
        cam->texPos = (cam->drawStart - cam->height / 2 + cam->lineHeight / 2) * cam->step;
        cam->y = cam->drawStart;
        while (cam->y < cam->drawEnd)
        {
            cam->texY = (int)cam->texPos;
            cam->texPos += cam->step;
            cam->color = get_texture_pixel_color(tex, cam->texX, cam->texY);
            if (cam->side == 1)
                cam->color = (cam->color >> 1) & 8355711;
            my_pixel_put_to_buffer(&vars->buffer, cam->x, cam->y, cam->color);
            (cam->y)++;
        }
        cam->x++;
    }
    calc_fps(&vars->fps);
    mlx_clear_window(vars->mlx, vars->win);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->buffer.img_ptr, 0, 0);
    return (0);
}
