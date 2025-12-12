/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:32:57 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/11 21:59:33 by alda-sil         ###   ########.fr       */
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
				map->Ceiling_color);
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
				map->Floor_color);
			(map->x_floor)++;
		}
		(cam->y)++;
	}
}

static void	draw_texture(t_texture *tex, t_camera *cam, t_vars *vars)
{
	cam->step = 1.0 * tex->height / cam->lineHeight;
	cam->texPos = (cam->drawStart - cam->height / 2 + cam->lineHeight / 2)
		* cam->step;
	cam->y = cam->drawStart;
	while (cam->y < cam->drawEnd)
	{
		cam->texY = (int)cam->texPos;
		cam->texPos += cam->step;
		cam->color = get_texture_pixel_color(tex, cam->texX, cam->texY);
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
		c->perpWallDist = (c->mapX - p->posX + (1 - p->stepX) / 2) / c->rayDirX;
	else
		c->perpWallDist = (c->mapY - p->posY + (1 - p->stepY) / 2) / c->rayDirY;
	c->lineHeight = (int)(c->height / c->perpWallDist);
	c->drawStart = -c->lineHeight / 2 + c->height / 2;
	if (c->drawStart < 0)
		c->drawStart = 0;
	c->drawEnd = c->lineHeight / 2 + c->height / 2;
	if (c->drawEnd >= c->height)
		c->drawEnd = c->height - 1;
	if (c->side == 0)
		c->wallX = p->posY + c->perpWallDist * c->rayDirY;
	else
		c->wallX = p->posX + c->perpWallDist * c->rayDirX;
	c->wallX -= floor(c->wallX);
	c->texX = (int)(c->wallX * (double)tex->width);
	if ((c->side == 0 && c->rayDirX > 0) || (c->side == 1
			&& c->rayDirY < 0))
		c->texX = tex->width - c->texX - 1;
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
