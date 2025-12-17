/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:21:56 by erick             #+#    #+#             */
/*   Updated: 2025/12/16 20:25:40 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	walk_up(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	new_posx;
	double	new_posy;

	new_posx = p->posx + cam->dir_x * fps->mv;
	new_posy = p->posy + cam->dir_y * fps->mv;
	if (map->map[(int)new_posy][(int)new_posx] != '1')
	{
		p->posx = new_posx;
		p->posy = new_posy;
	}
}

static void	walk_down(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	new_posx;
	double	new_posy;

	new_posx = p->posx - cam->dir_x * fps->mv;
	new_posy = p->posy - cam->dir_y * fps->mv;
	if (map->map[(int)new_posy][(int)new_posx] != '1')
	{
		p->posx = new_posx;
		p->posy = new_posy;
	}
}

static void	walk_right(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
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

static void	walk_left(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
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
	{
		free_mlx(vars);
		free_all(vars);
		exit(0);
	}
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
