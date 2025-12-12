/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:24:51 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/02 22:10:27 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_texture	*determinate_texture(t_camera *cam, t_vars *vars, t_map *map)
{
	(void) vars;
	if (cam->side == 0)
	{
		if (cam->rayDirX < 0)
			return (&map->WE);
		else
			return (&map->EA);
	}
	else
	{
		if (cam->rayDirY < 0)
			return (&map->NO);
		else
			return (&map->SO);
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
	fps->oldTime = fps->time;
	gettimeofday(&fps->timeOfDay, NULL);
	fps->time = fps->timeOfDay.tv_sec + (fps->timeOfDay.tv_usec / 1000000.0);
	;
	//printf("aqui está o tempo %f\n", fps->time);
	fps->frameTime = (fps->time - fps->oldTime);
	//printf("aqui esta o frameTime %f\n", fps->frameTime);
	fps->mv = fps->frameTime * 10.0;
	fps->rs = fps->frameTime * 10.0;
}