/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:41:40 by erocha-l          #+#    #+#             */
/*   Updated: 2026/01/07 21:00:15 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void free_walk(t_vars *vars)
{
    free_mlx(vars);
    free_all(vars);
    exit(0);
}


void	look_right(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	old_dir_x;
	double	old_plane_x;

	(void)p;
	(void)map;
	old_dir_x = cam->dir_x;
	cam->dir_x = cam->dir_x * cos(fps->rs) - cam->dir_y * sin(fps->rs);
	cam->dir_y = old_dir_x * sin(fps->rs) + cam->dir_y * cos(fps->rs);
	old_plane_x = cam->plane_x;
	cam->plane_x = cam->plane_x * cos(fps->rs) - cam->plane_y * sin(fps->rs);
	cam->plane_y = old_plane_x * sin(fps->rs) + cam->plane_y * cos(fps->rs);
}

void	look_left(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	old_dir_x;
	double	old_plane_x;

	(void)p;
	(void)map;
	old_dir_x = cam->dir_x;
	cam->dir_x = cam->dir_x * cos(-fps->rs) - cam->dir_y * sin(-fps->rs);
	cam->dir_y = old_dir_x * sin(-fps->rs) + cam->dir_y * cos(-fps->rs);
	old_plane_x = cam->plane_x;
	cam->plane_x = cam->plane_x * cos(-fps->rs) - cam->plane_y * sin(-fps->rs);
	cam->plane_y = old_plane_x * sin(-fps->rs) + cam->plane_y * cos(-fps->rs);
}