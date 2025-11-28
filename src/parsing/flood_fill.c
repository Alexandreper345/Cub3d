/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:25:52 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/27 20:10:40 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	flood_fill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == '\0')
		return (EXIT_FAILURE);
	if (map[y][x] == 'x' || map[y][x] == ' ')
		map[y][x] = '-';
	else if (map[y][x] == '1')
		return (EXIT_FAILURE);
	else if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'E' || map[y][x] == 'W')
	{
		map[y][x] = '-';
		return (EXIT_SUCCESS);
	}
	else if (map[y][x] == '-')
		return (EXIT_FAILURE);
	return (flood_fill(map, x + 1, y)
		&& flood_fill(map, x - 1, y)
		&& flood_fill(map, x, y + 1)
		&& flood_fill(map, x, y - 1));
}

char	**copy_matriz(int height, int width)
{
	char	**copy_matriz;
	int		i;
	int		j;

	copy_matriz = (char **)malloc(sizeof(char *) * (height + 3));
	if (!copy_matriz)
		return (NULL);
	i = -1;
	while (++i < height + 3)
	{
		copy_matriz[i] = (char *)malloc(sizeof(char) * (width + 3));
		if (!copy_matriz[i])
			return (NULL);
		j = -1;
		while (++j < width + 2)
			copy_matriz[i][j] = 'x';
		copy_matriz[i][j] = '\0';
	}
	return (copy_matriz);
}

void	expand_map(t_map *map, int width, int height)
{
	int	i;
	int	j;

	map->dup_map =copy_matriz(height, width);
	if (!map->dup_map)
		return ;
	i = 0;
	while(i < height)
	{
		j = 0;
		while(map->map[i][j])
		{
			map->dup_map[i + 1][j + 1] = map->map[i][j];
			j++;
		}
		i++;
	}
	map->dup_map[height + 2] = NULL;
}

int	init_process_flood(t_map *map)
{
	int		width;
	int		height;

	width = get_width_map(map->map);
	height = get_height_map(map->map);
	expand_map(map, width, height);
	if (!flood_fill(map->dup_map, 0, 0))
	{
		ft_error("flood fill map invalid");
		return (EXIT_FAILURE);
	}	
	return (EXIT_SUCCESS);
}
