/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:24:51 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/16 22:18:00 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_texture	*determinate_texture(t_camera *cam, t_vars *vars, t_map *map)
{
	(void)vars;
	if (cam->side == 0)
	{
		if (cam->raydirx < 0)
			return (&map->we);
		else
			return (&map->ea);
	}
	else
	{
		if (cam->raydiry < 0)
			return (&map->no);
		else
			return (&map->so);
	}
}

int	get_texture_pixel_color(t_texture *tex, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel_addr);
}

void	my_pixel_put_to_buffer(t_texture *img, int x, int y, int color)
{
	char	*pixel_addr;

	if (x < 0 || x >= 1080 || y < 0 || y >= 720)
		return ;
	pixel_addr = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel_addr = color;
}

void	calc_fps(t_fps *fps)
{
	fps->old_time = fps->time;
	gettimeofday(&fps->timeofday, NULL);
	fps->time = fps->timeofday.tv_sec + (fps->timeofday.tv_usec / 1000000.0);
	fps->frame_time = (fps->time - fps->old_time);
	fps->mv = fps->frame_time * 10.0;
	fps->rs = fps->frame_time * 10.0;
}
