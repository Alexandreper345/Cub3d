/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:26:28 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/25 22:00:42 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	init_struct(t_vars *vars)
{
	t_map	*map;
	t_player *player;

	map = malloc(sizeof(t_map));
	if (!map)
		return (EXIT_FAILURE);
	player = malloc(sizeof(t_player));
	if (!player)
		return (EXIT_FAILURE);
	vars->map = map;
	vars->player = player;
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (EXIT_FAILURE);
	if (check_file_path(argc, argv) || init_struct(vars))
		return (EXIT_FAILURE);
	if (init_matriz(vars->map, argv[1]) || parsing(vars->map, vars->player))
		return (EXIT_FAILURE);
	/*
	init_vars(vars, argv[1]);
	for (int i = 0; vars->map->matriz[i] != NULL; i++)
		printf("lina: %s", vars->map->matriz[i]);
	printf("tex: %s\n", vars->map->NO_path);
	game(vars);
	*/
}
