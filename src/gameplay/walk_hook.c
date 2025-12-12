/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:21:56 by erick             #+#    #+#             */
/*   Updated: 2025/12/11 22:18:51 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	walk_up(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = p->posX + cam->dirX * fps->mv;
	new_pos_y = p->posY + cam->dirY * fps->mv;
	if (map->map[(int)new_pos_y][(int)new_pos_x] != '1')
	{
		p->posX = new_pos_x;
		p->posY = new_pos_y;
	}
}

static void	walk_down(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = p->posX - cam->dirX * fps->mv;
	new_pos_y = p->posY - cam->dirY * fps->mv;
	if (map->map[(int)new_pos_y][(int)new_pos_x] != '1')
	{
		p->posX = new_pos_x;
		p->posY = new_pos_y;
	}
}

static void	walk_right(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	old_dir_x;
	double	old_plane_x;

	(void)p;
	(void)map;
	old_dir_x = cam->dirX;
	cam->dirX = cam->dirX * cos(fps->rs) - cam->dirY * sin(fps->rs);
	cam->dirY = old_dir_x * sin(fps->rs) + cam->dirY * cos(fps->rs);
	old_plane_x = cam->planeX;
	cam->planeX = cam->planeX * cos(fps->rs) - cam->planeY * sin(fps->rs);
	cam->planeY = old_plane_x * sin(fps->rs) + cam->planeY * cos(fps->rs);
}

static void	walk_left(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	old_dir_x;
	double	old_plane_x;

	(void)p;
	(void)map;
	old_dir_x = cam->dirX;
	cam->dirX = cam->dirX * cos(-fps->rs) - cam->dirY * sin(-fps->rs);
	cam->dirY = old_dir_x * sin(-fps->rs) + cam->dirY * cos(-fps->rs);
	old_plane_x = cam->planeX;
	cam->planeX = cam->planeX * cos(-fps->rs) - cam->planeY * sin(-fps->rs);
	cam->planeY = old_plane_x * sin(-fps->rs) + cam->planeY * cos(-fps->rs);
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
		walk_up(map, p, fps, cam);
	if (keycode == XK_s)
		walk_down(map, p, fps, cam);
	if (keycode == XK_d)
		walk_right(map, p, fps, cam);
	if (keycode == XK_a)
		walk_left(map, p, fps, cam);
	return (0);
}
