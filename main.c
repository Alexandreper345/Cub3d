/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:26:28 by alda-sil          #+#    #+#             */
/*   Updated: 2025/10/15 15:44:12 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	main(int argc, char **argv)
{
	t_vars vars;

	init_vars(&vars);
	if (argc != 2)
	{
		perror("missing map file .cub");
		return (0);
	}
	simple_parser(&vars.map, argv[1]);
	for (int i = 0; vars.map.map[i] != NULL; i++)
		printf("lina: %s", vars.map.map[i]);
	//if (parsing(argc, argv))
	//	return (1);
	game(&vars);
}