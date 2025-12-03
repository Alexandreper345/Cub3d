/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:05:52 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/02 22:06:54 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	calc_cam_vars(t_camera *cam, t_vars *vars)
{
	cam->hit = 0;
	cam->camX = 2 * cam->x / (double)vars->width - 1;
	cam->rayDirX = cam->dirX + cam->planeX * cam->camX;
	cam->rayDirY = cam->dirY + cam->planeY * cam->camX;
	cam->mapX = (int)vars->player.posX;
	cam->mapY = (int)vars->player.posY;
}

static void	delta_dist(t_camera *cam, t_player *player)
{
	if (cam->rayDirX == 0)
		cam->deltaDistX = 1e30;
	else
		cam->deltaDistX = fabs(1 / cam->rayDirX);
	if (cam->rayDirY == 0)
		cam->deltaDistY = 1e30;
	else
		cam->deltaDistY = fabs(1 / cam->rayDirY);
}

static void	delta_n_side_dist(t_camera *cam, t_player *player)
{
	delta_dist(cam, player);
	if (cam->rayDirX < 0)
	{
		player->stepX = -1;
		cam->sideDistX = (player->posX - cam->mapX) * cam->deltaDistX;
	}
	else
	{
		player->stepX = 1;
		cam->sideDistX = (cam->mapX + 1.0 - player->posX) * cam->deltaDistX;
	}
	if (cam->rayDirY < 0)
	{
		player->stepY = -1;
		cam->sideDistY = (player->posY - cam->mapY) * cam->deltaDistY;
	}
	else
	{
		player->stepY = 1;
		cam->sideDistY = (cam->mapY + 1.0 - player->posY) * cam->deltaDistY;
	}
}

void	dda(t_map *map, t_camera *cam, t_player *player, t_vars *vars)
{
	calc_cam_vars(cam, vars);
	delta_n_side_dist(cam, player);
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
		if (cam->mapX < 0 || cam->mapX >= vars->width || cam->mapY < 0
			|| cam->mapY >= vars->height)
			cam->hit = 1;
		if (map->matriz[cam->mapY][cam->mapX] == '1')
			cam->hit = 1;
	}
}
