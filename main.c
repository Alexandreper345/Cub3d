/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:26:28 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/22 23:12:02 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

static void	init_fps(t_fps fps)
{
	fps.time = 0;
	fps.old_time = 0;
	gettimeofday(&fps.timeofday, NULL);
	fps.time = fps.timeofday.tv_sec;
	fps.frame_time = 0;
	fps.mv = 0;
	fps.rs = 0;
}

int	init_struct(t_vars *vars)
{
	t_map		*map;
	t_player	*player;
	
	map = malloc(sizeof(t_map));
	player = malloc(sizeof(t_player));
	if (!map || !player)
		return (EXIT_FAILURE);
	init_fps(vars->fps);
	vars->map = map;
	vars->player = player;
	vars->width = 1080;
	vars->height = 720;
	vars->camera.dir_x = 0;
	vars->camera.dir_y = 0;
	vars->camera.plane_x = 0;
	vars->camera.plane_y = 0;
	return (EXIT_SUCCESS);
}

static void init_null(t_vars *vars)
{
	ft_memset(vars->map, 0, sizeof(t_map));
	ft_memset(vars->map->map, 0, sizeof(t_map));
	ft_memset(vars->map->matriz, 0, sizeof(t_map));
	vars->map->no_path = NULL;
	vars->map->so_path = NULL;
	vars->map->we_path = NULL;
	vars->map->ea_path = NULL;
	vars->player = NULL;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->buffer.img_ptr = NULL;
	vars->buffer.addr = NULL;
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (EXIT_FAILURE);
	init_null(vars);
	if (check_file_path(argc, argv) || init_struct(vars))
	{
		free_all(vars);
		return (EXIT_FAILURE);
	}
	if (init_matriz(vars->map, argv[1]) || parsing(vars->map, vars))
	{
		free_all(vars);
		return (EXIT_FAILURE);
	}
	game(vars);
	free_all(vars);
	return (0);
}
