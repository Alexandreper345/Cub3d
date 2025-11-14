/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:08:42 by erocha-l          #+#    #+#             */
/*   Updated: 2025/10/22 19:52:12 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_map	*init_map(t_map *map, char *map_path)
{
	init_matriz(map, map_path);
	return (map);
}

void	init_vars(t_vars *vars, char *map_path)
{
	t_player	*player;
	t_map		*map;

	vars->map =  init_map(map, map_path);
	vars->mlx = NULL;
	vars->win = NULL;
}
