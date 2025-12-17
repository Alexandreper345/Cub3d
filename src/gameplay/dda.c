/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:05:52 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/16 20:27:30 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	calc_cam_vars(t_camera *cam, t_vars *vars)
{
	cam->hit = 0;
	cam->cam_x = 2 * cam->x / (double)vars->width - 1;
	cam->raydirx = cam->dir_x + cam->plane_x * cam->cam_x;
	cam->raydiry = cam->dir_y + cam->plane_y * cam->cam_x;
	cam->mapx = (int)vars->player->posx;
	cam->mapy = (int)vars->player->posy;
}

static void	delta_dist(t_camera *cam, t_player *player)
{
	(void)player;
	if (cam->raydirx == 0)
		cam->delta_dist_x = 1e30;
	else
		cam->delta_dist_x = fabs(1 / cam->raydirx);
	if (cam->raydiry == 0)
		cam->delta_dist_y = 1e30;
	else
		cam->delta_dist_y = fabs(1 / cam->raydiry);
}

static void	delta_n_side_dist(t_camera *cam, t_player *player)
{
	delta_dist(cam, player);
	if (cam->raydirx < 0)
	{
		player->stepx = -1;
		cam->side_dist_x = (player->posx - cam->mapx) * cam->delta_dist_x;
	}
	else
	{
		player->stepx = 1;
		cam->side_dist_x = (cam->mapx + 1.0 - player->posx) * cam->delta_dist_x;
	}
	if (cam->raydiry < 0)
	{
		player->stepy = -1;
		cam->side_dist_y = (player->posy - cam->mapy) * cam->delta_dist_y;
	}
	else
	{
		player->stepy = 1;
		cam->side_dist_y = (cam->mapy + 1.0 - player->posy) * cam->delta_dist_y;
	}
}

void	dda(t_map *map, t_camera *cam, t_player *player, t_vars *vars)
{
	calc_cam_vars(cam, vars);
	delta_n_side_dist(cam, player);
	while (cam->hit == 0)
	{
		if (cam->side_dist_x < cam->side_dist_y)
		{
			cam->side_dist_x += cam->delta_dist_x;
			cam->mapx += player->stepx;
			cam->side = 0;
		}
		else
		{
			cam->side_dist_y += cam->delta_dist_y;
			cam->mapy += player->stepy;
			cam->side = 1;
		}
		if (cam->mapx < 0 || cam->mapx >= map->width || cam->mapy < 0
			|| cam->mapy >= map->height)
			cam->hit = 1;
		else if (map->map[cam->mapy][cam->mapx] == '1')
			cam->hit = 1;
	}
}
