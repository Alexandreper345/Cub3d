/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:21:56 by erick             #+#    #+#             */
/*   Updated: 2025/12/03 21:13:26 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	walk_up(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	newPosX;
	double	newPosY;

	newPosX = p->posX + cam->dirX * fps->mv;
	newPosY = p->posY + cam->dirY * fps->mv;
	if (map->matriz[(int)newPosY][(int)newPosX] == '0')
	{
		p->posX = newPosX;
		p->posY = newPosY;
	}
}

static void	walk_down(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	newPosX;
	double	newPosY;

	newPosX = p->posX - cam->dirX * fps->mv;
	newPosY = p->posY - cam->dirY * fps->mv;
	if (map->matriz[(int)newPosY][(int)newPosX] == '0')
	{
		p->posX = newPosX;
		p->posY = newPosY;
	}
}

static void	walk_right(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	oldDirX;
	double	oldPlaneX;

	(void)p;
	(void)map;
	oldDirX = cam->dirX;
	cam->dirX = cam->dirX * cos(fps->rs) - cam->dirY * sin(fps->rs);
	cam->dirY = oldDirX * sin(fps->rs) + cam->dirY * cos(fps->rs);
	oldPlaneX = cam->planeX;
	cam->planeX = cam->planeX * cos(fps->rs) - cam->planeY * sin(fps->rs);
	cam->planeY = oldPlaneX * sin(fps->rs) + cam->planeY * cos(fps->rs);
}

static void	walk_left(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	oldDirX;
	double	oldPlaneX;

	(void)p;
	(void)map;
	oldDirX = cam->dirX;
	cam->dirX = cam->dirX * cos(-fps->rs) - cam->dirY * sin(-fps->rs);
	cam->dirY = oldDirX * sin(-fps->rs) + cam->dirY * cos(-fps->rs);
	oldPlaneX = cam->planeX;
	cam->planeX = cam->planeX * cos(-fps->rs) - cam->planeY * sin(-fps->rs);
	cam->planeY = oldPlaneX * sin(-fps->rs) + cam->planeY * cos(-fps->rs);
}

int	walk(int keycode, t_vars *vars)
{
	t_map		*map;
	t_player	*p;
	t_fps		*fps;
	t_camera	*cam;

	map = vars->map;
	p = vars->player;
	fps = &vars->fps;
	cam = &vars->camera;
	if (keycode == XK_Escape)
		free_and_exit(vars);
	if (keycode == XK_w)
	{
		printf("cai aqui\n");
		walk_up(map, p, fps, cam);
	}
	if (keycode == XK_s)
		walk_down(map, p, fps, cam);
	if (keycode == XK_d)
		walk_right(map, p, fps, cam);
	if (keycode == XK_a)
		walk_left(map, p, fps, cam);
	return(0);
}
