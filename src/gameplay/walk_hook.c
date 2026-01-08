/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:21:56 by erick             #+#    #+#             */
/*   Updated: 2026/01/07 21:10:16 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	walk_up(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	new_posx;
	double	new_posy;

	new_posx = 0;
	new_posy = 0;
	new_posx = p->posx + cam->dir_x * fps->mv;
	new_posy = p->posy + cam->dir_y * fps->mv;
	if (new_posy > (double)map->height)
		return ;
	if (new_posy < 0)
		return ;
	if (new_posx > (double)map->width)
		return ;
	if (new_posx < 0)
		return ;
	if (map->map[(int)new_posy][(int)new_posx] != '1' && map->map[(int)new_posy][(int)new_posx])
	{
		p->posx = new_posx;
		p->posy = new_posy;
	}
}

static void	walk_down(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	new_posx;
	double	new_posy;

	new_posx = 0;
	new_posy = 0;
	new_posx = p->posx - cam->dir_x * fps->mv;
	new_posy = p->posy - cam->dir_y * fps->mv;
	if (new_posy > (double)map->height)
		return ;
	if (new_posy < 0)
		return ;
	if (new_posx > (double)map->width)
		return ;
	if (new_posx < 0)
		return ;
	if (map->map[(int)new_posy][(int)new_posx] != '1' && map->map[(int)new_posy][(int)new_posx])
	{
		p->posx = new_posx;
		p->posy = new_posy;
	}
}

static void	walk_right(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	new_posx;
	double	new_posy;

	new_posx = 0;
	new_posy = 0;
	new_posx = p->posx + cam->dir_y * fps->mv;
	new_posy = p->posy - cam->dir_x * fps->mv;
	if (new_posy > (double)map->height)
		return ;
	if (new_posy < 0)
		return ;
	if (new_posx > (double)map->width)
		return ;
	if (new_posx < 0)
		return ;
	if (map->map[(int)new_posy][(int)new_posx] != '1' && map->map[(int)new_posy][(int)new_posx])
	{
		p->posx = new_posx;
		p->posy = new_posy;
	}
}

static void	walk_left(t_map *map, t_player *p, t_fps *fps, t_camera *cam)
{
	double	new_posx;
	double	new_posy;

	new_posx = 0;
	new_posy = 0;
	new_posx = p->posx - cam->dir_y * fps->mv;
	new_posy = p->posy + cam->dir_x * fps->mv;
	if (new_posy > (double)map->height)
		return ;
	if (new_posy < 0)
		return ;
	if (new_posx > (double)map->width)
		return ;
	if (new_posx < 0)
		return ;
	if (map->map[(int)new_posy][(int)new_posx] != '1' && map->map[(int)new_posy][(int)new_posx])
	{
		p->posx = new_posx;
		p->posy = new_posy;
	}
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
		free_walk(vars);
	if (keycode == XK_w)
		walk_up(map, p, fps, cam);
	if (keycode == XK_s)
		walk_down(map, p, fps, cam);
	if (keycode == XK_d)
		walk_left(map, p, fps, cam);
	if (keycode == XK_a)
		walk_right(map, p, fps, cam);
	if (keycode == XK_Left)
		look_left(map, p, fps, cam);
	if (keycode == XK_Right)
		look_right(map, p, fps, cam);
	return (0);
}
