/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:26:28 by alda-sil          #+#    #+#             */
/*   Updated: 2025/10/14 19:36:18 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars *vars;

	if (check_file_path(argc, argv) || init_matriz(vars->map, argv[1]))
		return (EXIT_FAILURE);
	if (parsing(vars->map) || )
		return (EXIT_FAILURE);
	
	//init_vars(vars, argv[1]);
	//for (int i = 0; vars.map.map[i] != NULL; i++)
	//	printf("lina: %s", vars.map.map[i]);
	//game(&vars);
}