/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:25:52 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/05 21:50:22 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	flood_fill(char **dup_map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '\0')
		return (EXIT_FAILURE);
	if (dup_map[x][y] == 'x' || dup_map[x][y] == ' ')
		dup_map[x][y] == '-';
	if (dup_map[x][y] == '1')
		return (EXIT_FAILURE);
	if(dup_map[x][y] == '0' || dup_map[x][y] == 'N' ||
		dup_map[x][y] == 'S' || dup_map[x][y] == 'E' || dup_map[x][y] == 'W')
	{
		dup_map[x][y] == '-';
		return (EXIT_SUCCESS);
	}
	if (dup_map[x][y] == '-')
		return (EXIT_FAILURE);
	return (flood_fill(dup_map, x + 1, y) && flood_fill(dup_map, x - 1, y) 
			flood_fill(dup_map, x, y + 1) &&  flood_fill(dup_map, x, y - 1));
}

char	**copy_matriz(int height, int width)
{
	char	**copy_matriz;
	int		i;
	int		j;

	copy_matriz = (char **)malloc(sizeof(char *) * height + 3);
	if (!copy_matriz)
		return (NULL);
	i = -1;
	while (++i < height + 2)
	{
		copy_matriz[i] = (char *)malloc(sizeof(char) * width + 3);
		if (!copy_matriz)
			return (NULL);
		j = -1;
		while (++j < width + 2)
			copy_matriz[i][j] = 'x';
		copy_matriz[i][j] = '\0';
	}
	return (copy_matriz);
}

char	**expand_map(char **dup_map, char **map, int width, int height)
{
	int	i;
	int	j;

	i = -1;
	while(++i < height)
	{
		j = 0;
		while(dup_map[i][j] && dup_map[i][j] != '\n')
		{
			dup_map[i + 1][j + 1] = map[i][j];
			j++;
		}
	}
	dup_map[height + 2] = NULL;
	return (dup_map);
}

int	init_process_flood(t_map *map)
{
	int		width;
	int		height;
	char	**dup_map;
	char	**map_matriz;

	map_matriz = get_position_map(map->matriz);	
	width = get_width_map(map_matriz);
	height = get_height_map(map_matriz);
	dup_map = copy_matriz(height, width);
	if (!dup_map)
		return (EXIT_FAILURE);
	dup_map = expand_map(dup_map , map_matriz, height, width);
	if (flood_fill(dup_map, width, height))
		return (EXIT_FAILURE);
	if (get_position_player(map_matriz))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}