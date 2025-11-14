/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:43:08 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 22:02:23 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	validate_map(char **map, int width, int height)
{
	while (map[++height])
	{
		while (map[height][++width])
		{
			if (map[height][0] == '\n')
				return (EXIT_FAILURE);
			if (map[height][width] != '\n' && map[height][width] != '1' &&
				map[height][width] != '0' && ft_strncmp(map[height][width], "NO", 2) && 
				ft_strncmp(map[height][width], "SO", 2) && ft_strncmp(map[height][width], "WE", 2)
				ft_strncmp(map[height][width], "EA", 2) && map[height][width] != ' ')
					return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	coord_map(t_map *map)
{
	int		i;
	int		j;
	char	**temp;

	i = -1;
	while(matriz[++i])
	{
		j = 0;
		if(matriz[i][j] == '1')
		{
			if (validate_map(map, i, j))
				return (EXIT_FAILURE);	
			map->map = matriz[i][j];
			return (EXIT_SUCCESS);
		}	
	}
	return (EXIT_FAILURE);
}