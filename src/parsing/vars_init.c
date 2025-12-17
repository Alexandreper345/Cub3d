/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:08:42 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/16 20:28:23 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "../../include/cub3d.h"

static void	init_fps(t_fps *fps)
{
	ft_memset(fps, 0, sizeof(t_fps));
	fps->time = 0;
	fps->old_time = 0;
	gettimeofday(&fps->timeofday, NULL);
	fps->time = fps->timeofday.tv_sec;
	fps->frame_time = 0;
	fps->mv = 0;
	fps->rs = 0;
}

t_map	*init_map(t_map *map, char *map_path)
{
	init_matriz(map, map_path);
	return (map);
}

void	init_vars(t_vars *vars, char *map_path)
{
	t_player	*player;
	t_map		*map;

	vars->map = init_map(map, map_path);
	vars->mlx = NULL;
	vars->win = NULL;
	vars->height = 720;
	vars->width = 1080;
	ft_memset(&vars->player, 0, sizeof(t_player));
	ft_memset(&vars->camera, 0, sizeof(t_camera));
	ft_memset(&vars->map->no, 0, sizeof(t_texture));
	ft_memset(&vars->map->we, 0, sizeof(t_texture));
	ft_memset(&vars->map->so, 0, sizeof(t_texture));
	ft_memset(&vars->map->ea, 0, sizeof(t_texture));
	ft_memset(&vars->buffer, 0, sizeof(t_texture));
	init_fps(&vars->fps);
	vars->player.posx = 7.0;
	vars->player.posy = 3.0;
	vars->camera.dir_x = -1.0;
	vars->camera.dir_y = 0.0;
	vars->camera.plane_x = 0.0;
	vars->camera.plane_y = -0.66;
	vars->camera.height = 720;
}*/
/*void    init_vars(t_vars *vars)
{
	vars->height = 720;
	vars->width = 1080;
	vars->mlx = NULL;
	vars->win = NULL;
	ft_memset(&vars->map, 0, sizeof(t_map));
	ft_memset(&vars->player, 0, sizeof(t_player));
	ft_memset(&vars->camera, 0, sizeof(t_camera));
	ft_memset(&vars->map.no, 0, sizeof(t_texture));
	ft_memset(&vars->map.we, 0, sizeof(t_texture));
	ft_memset(&vars->map.so, 0, sizeof(t_texture));
	ft_memset(&vars->map.ea, 0, sizeof(t_texture));
	ft_memset(&vars->buffer, 0, sizeof(t_texture));
	init_fps(&vars->fps);
	vars->player.posx = 7.0;
	vars->player.posy = 3.0;
	vars->camera.dir_x = -1.0;
	vars->camera.dir_y = 0.0;
	vars->camera.plane_x = 0.0;
	vars->camera.plane_y = -0.66;
	vars->camera.height = 720;
}*/