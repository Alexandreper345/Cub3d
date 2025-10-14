/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:32:57 by erocha-l          #+#    #+#             */
/*   Updated: 2025/10/14 07:37:25 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int gameplay(t_vars *vars)
{
    t_map       *map;
    t_camera    *cam;
    t_player    *player;
    int         x;
    
    map = vars->map;
    cam = vars->camera;
    player = vars->player;
    x = 0;
    while(x < map->width)
    {
        cam->hit = 0;
        cam->camX = 2 * x / double(map->width) - 1;
        cam->rayDirX = cam->dirX + cam->planeX * cam->cameraX;
        cam->rayDirY = cam->dirY + cam->PlaneY * cam->cameraX;  
        cam->mapX = vars->player->posX;
        cam->mapY = vars->player->posY;
        if (cam->rayDirX == 0)
            cam->deltaDistX = 1e30; 
        else
            cam->deltaDistX = fabs(1 / cam->rayDirX);
        if (cam->rayDiry == 0)
            cam->deltaDisty = 1e30; 
        else
            cam->deltaDisty = fabs(1 / cam->rayDiry);
        if (cam->rayDirX < 0)
        {
            player->stepX = -1;
            map->sideDistX = (player->posX - cam->mapX) * cam->deltaDistX;
        }
        else
        {
            player->stepX = 1;
            map->sideDistX = (cam->mapX + 1.0 - player->posX ) * cam->deltaDistX;            
        }
        if (cam->rayDirY < 0)
        {
            player->stepY = -1;
            map->sideDistY = (player->posY - cam->mapY) * cam->deltaDistY;
        }
        else
        {
            player->stepY = 1;
            map->sideDistY = (cam->mapY + 1.0 - player->posY ) * cam->deltaDistY;            
        }
        while (cam->hit == 0)
        {
            if (cam->sideDistX < cam->sideDistY)
            {
                cam->sideDistX += cam->deltaDistX;
                cam->mapX += player->stepX;
                cam->side = 0;
            }
            else
            {
                cam->sideDistY += cam->deltaDistY;
                cam->mapY += player->stepY;
                cam->side = 1;
            }
            if (map->map[cam->mapX][cam->mapY] > 0)
                hit = 1
        }
        if (side == 0)
            cam->perpWallDist = (cam->sideDistX - cam->deltaDistX);
        else
            cam->perpWallDist = (cam->sideDistY - cam->deltaDistY);
        cam->lineHeight = (int)(player->height / map->perpWallDist);
        cam->drawStart = -cam->lineHeight / 2 + player->height / 2;
        if (cam->drawStart < 0)
            cam->drawStart = 0;
        cam->drawEnd = cam->lineHeight / 2 + player->height / 2;
        if (cam->drawEnd >= player->height)
            cam->drawEnd = player->height - 1;
        if (cam->side == 0)
            cam->wallX = player->posY * cam->perpWallDist * cam->rayDirY;
        else
            cam->wallX = player->posX * cam->perpWallDist * cam->rayDirX;
        cam->wallX -= floor(cam->wallX);
        x++;
    }
}
