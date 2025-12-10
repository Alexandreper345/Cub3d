/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:26:28 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/09 20:03:09 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

static void	init_buffer(t_vars *vars)
{
	printf("Inicializando o buffer de imagem...\n");
	vars->buffer.img_ptr = mlx_new_image(vars->mlx, vars->width, vars->height);
	if (vars->buffer.img_ptr == NULL)
	{
		printf("Erro fatal: mlx_new_image() para o buffer falhou.\n");
		exit(1);
	}
	vars->buffer.addr = mlx_get_data_addr(vars->buffer.img_ptr,
			&vars->buffer.bpp, &vars->buffer.line_len, &vars->buffer.endian);
	printf("Buffer inicializado. Endereço (addr): %p\n", vars->buffer.addr);
}

static void	init_fps(t_fps *fps)
{
	fps->time = 0;
	fps->oldTime = 0;
	gettimeofday(&fps->timeOfDay, NULL);
	fps->time = fps->timeOfDay.tv_sec;
	fps->frameTime = 0;
	fps->mv = 0;
	fps->rs = 0;
}

int	init_struct(t_vars *vars, t_fps	*fps)
{
	t_map		*map;
	t_player 	*player;
	t_camera	*camera;
	t_texture	*buffer;

	map = malloc(sizeof(t_map));
	player = malloc(sizeof(t_player));
	camera = malloc(sizeof(t_camera));
	fps = malloc(sizeof(t_fps));
	buffer = malloc(sizeof(t_texture));
	if (!map || !player || !fps || !camera || !buffer)
		return (EXIT_FAILURE);
	init_fps(fps);
	vars->map = map;
	vars->player = player;
	vars->fps = *fps;
	vars->camera = *camera;
	vars->buffer = *buffer;
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_fps	*fps;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (EXIT_FAILURE);
	if (check_file_path(argc, argv) || init_struct(vars, fps))
		return (EXIT_FAILURE);
	if (init_matriz(vars->map, argv[1]) || parsing(vars->map, vars))
		return (EXIT_FAILURE);
	/*
	init_vars(vars, argv[1]);
	for (int i = 0; vars->map->matriz[i] != NULL; i++)
		printf("lina: %s", vars->map->matriz[i]);
	printf("tex: %s\n", vars->map->NO_path);
	*/
	game(vars);
}
