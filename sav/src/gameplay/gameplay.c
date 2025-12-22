/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:32:57 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/16 20:27:30 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	cal_floor_and_ceilling(t_map *map, t_camera *cam, t_vars *vars)
{
	while (cam->y < vars->height / 2)
	{
		map->x_ceil = 0;
		while (map->x_ceil < vars->width)
		{
			my_pixel_put_to_buffer(&vars->buffer, map->x_ceil, cam->y,
				map->ceiling_color);
			(map->x_ceil)++;
		}
		(cam->y)++;
	}
	while (cam->y < vars->height)
	{
		map->x_floor = 0;
		while (map->x_floor < vars->width)
		{
			my_pixel_put_to_buffer(&vars->buffer, map->x_floor, cam->y,
				map->floor_color);
			(map->x_floor)++;
		}
		(cam->y)++;
	}
}

static void	draw_texture(t_texture *tex, t_camera *cam, t_vars *vars)
{
	cam->step = 1.0 * tex->height / cam->line_height;
	cam->tex_pos = (cam->draw_start - cam->height / 2 + cam->line_height / 2)
		* cam->step;
	cam->y = cam->draw_start;
	while (cam->y < cam->draw_end)
	{
		cam->tex_y = (int)cam->tex_pos;
		cam->tex_pos += cam->step;
		cam->color = get_texture_pixel_color(tex, cam->tex_x, cam->tex_y);
		if (cam->side == 1)
			cam->color = (cam->color >> 1) & 8355711;
		my_pixel_put_to_buffer(&vars->buffer, cam->x, cam->y, cam->color);
		(cam->y)++;
	}
}

static void	draw_walls(t_map *map, t_camera *c, t_player *p, t_vars *vars)
{
	t_texture	*tex;

	tex = determinate_texture(c, vars, map);
	if (c->side == 0)
		c->perpwalldist = (c->mapx - p->posx + (1 - p->stepx) / 2) / c->raydirx;
	else
		c->perpwalldist = (c->mapy - p->posy + (1 - p->stepy) / 2) / c->raydiry;
	c->line_height = (int)(c->height / c->perpwalldist);
	c->draw_start = -c->line_height / 2 + c->height / 2;
	if (c->draw_start < 0)
		c->draw_start = 0;
	c->draw_end = c->line_height / 2 + c->height / 2;
	if (c->draw_end >= c->height)
		c->draw_end = c->height - 1;
	if (c->side == 0)
		c->wall_x = p->posy + c->perpwalldist * c->raydiry;
	else
		c->wall_x = p->posx + c->perpwalldist * c->raydirx;
	c->wall_x -= floor(c->wall_x);
	c->tex_x = (int)(c->wall_x * (double)tex->width);
	if ((c->side == 0 && c->raydirx > 0) || (c->side == 1
			&& c->raydiry < 0))
		c->tex_x = tex->width - c->tex_x - 1;
	draw_texture(tex, c, vars);
}

int	gameplay(t_vars *vars)
{
	t_map		*map;
	t_camera	*cam;
	t_player	*player;

	map = vars->map;
	cam = &vars->camera;
	player = vars->player;
	cam->height = 720;
	cam->x = 0;
	cam->y = 0;
	cal_floor_and_ceilling(map, cam, vars);
	while (cam->x < vars->width)
	{
		dda(map, cam, player, vars);
		draw_walls(map, cam, player, vars);
		cam->x++;
	}
	calc_fps(&vars->fps);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->buffer.img_ptr, 0, 0);
	return (0);
}
