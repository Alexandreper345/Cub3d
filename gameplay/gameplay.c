/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:32:57 by erocha-l          #+#    #+#             */
/*   Updated: 2025/10/16 12:22:27 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int gameplay(t_vars *vars)
{
    printf("entrei até aqui!\n");
    t_map       *map;
    t_camera    *cam;
    t_player    *player;
    t_texture   *tex;
    int         x;
    
    map = &vars->map;
    cam = &vars->camera;
    player = &vars->player;
    cam->height = 720;
    x = 0;
    cam->dirX = 1;
    cam->dirY = 1;
    cam->planeX = 0.66;
    cam->planeY = 0.0;
    while(x < vars->width)
    {
        cam->hit = 0;
        cam->camX = 2 * x / (double)vars->width - 1;
        cam->rayDirX = cam->dirX + cam->planeX * cam->camX;
        cam->rayDirY = cam->dirY + cam->planeY * cam->camX;
        cam->mapX = vars->player.posX;
        cam->mapY = vars->player.posY;
        if (cam->rayDirX == 0)
            cam->deltaDistX = 1e30;
        else
            cam->deltaDistX = fabs(1 / cam->rayDirX);
        if (cam->rayDirY == 0)
            cam->deltaDistY = 1e30; 
        else
            cam->deltaDistY = fabs(1 / cam->rayDirY);
        if (cam->rayDirX < 0)
        {
            player->stepX = -1;
            cam->sideDistX = (player->posX - cam->mapX) * cam->deltaDistX;
        }
        else
        {
            player->stepX = 1;
            cam->sideDistX = (cam->mapX + 1.0 - player->posX ) * cam->deltaDistX;            
        }
        if (cam->rayDirY < 0)
        {
            player->stepY = -1;
            cam->sideDistY = (player->posY - cam->mapY) * cam->deltaDistY;
        }
        else
        {
            player->stepY = 1;
            cam->sideDistY = (cam->mapY + 1.0 - player->posY ) * cam->deltaDistY;            
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
            if (cam->mapX < 0 || cam->mapX >= vars->width || cam->mapY < 0 || cam->mapY >= vars->height) // Use a altura real do mapa
            {
                cam->hit = 1; // Para o loop como se tivesse batido numa parede
                // Pode até definir uma cor de "vazio" aqui se quiser
            }
            if (map->map[cam->mapY][cam->mapX] == '1')
                cam->hit = 1;
        }
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
            my_pixel_put_to_buffer(&vars->buffer, x, cam->y, cam->color);
            (cam->y)++;
        }
        x++;
    }
    calc_fps(&vars->fps);
    mlx_clear_window(vars->mlx, vars->win);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->buffer.img_ptr, 0, 0);
}
