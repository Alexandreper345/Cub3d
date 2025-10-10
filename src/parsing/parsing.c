/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:05:56 by alda-sil          #+#    #+#             */
/*   Updated: 2025/10/09 21:50:46 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	format_texture(t_map *map)
{
	int	i;

	i = 0;
	if (map->matriz[i] != 'NO' || map->matriz[i] != 'WE' || 
		map->matriz[i] != 'SO' || map->matriz[i] != 'EA')
	{
		//free(matrix) free matriz
		ft_error("argument invalid");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	split_color(t_map *map)
{

	map->Floor = ft_split(map->*Floor, ',');
	map->Ceiling = ft_split(map->*Ceiling, ',');
}


int	get_color(t_map *map)
{
	int	i;

	si = 0;
	while (map->matriz[i] != 'F' || map->matriz[i] != 'C')
	{
		if (map->matriz[i] == 'F')
			map->Floor = map->matriz[i][1];
		else if (map->matriz[i] == 'C')
			map->Ceiling = map->matriz[i][1];
		i++
	}
	if (!map->Floor || !map->Ceiling)
	{
		ft_error("map invalid, because not exist color");
		return (EXIT_FAILURE);
	}
	split_color(map);
	return (EXIT_SUCCESS);
}

int	parsing(t_map *map)
{
	if (format_texture(map))
		return (EXIT_FAILURE);
	if (get_color(map))
		return (EXIT_FAILURE);

}