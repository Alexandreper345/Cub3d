/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:25:52 by alda-sil          #+#    #+#             */
/*   Updated: 2026/01/07 21:55:22 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	flood_fill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == '\0')
		return (EXIT_FAILURE);
	if (map[y][x] == 'x' || map[y][x] == ' ' || map[y][x] == '\t')
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

int	copy_matriz(t_map *map, int height, int width)
{
	char	**copy_matriz;
	int		i;
	int		j;

	copy_matriz = ft_calloc((height + 3), sizeof(char *));
	if (!copy_matriz)
		return (EXIT_FAILURE);
	i = 0;
	while (i < height + 2)
	{
		copy_matriz[i] = ft_calloc((width + 3),sizeof(char));
		if (!copy_matriz[i])
		{
			free_matriz(copy_matriz);
			return (EXIT_FAILURE);
		}
		j = 0;
		while (j < width + 1)
			copy_matriz[i][j++] = 'x';
		copy_matriz[i][j] = '\0';
		i++;
	}
	map->dup_map = copy_matriz;
	return (EXIT_SUCCESS);
}

int	expand_map(t_map *map, int width, int height)
{
	int	i;
	int	j;

	if (copy_matriz(map, height, width))
		return (EXIT_FAILURE);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (map->map[i][j] && map->map[i][j] != '\n')
		{		
			map->dup_map[i + 1][j + 1] = map->map[i][j];
			j++;
		}
		i++;
	}
	map->dup_map[height + 2] = NULL;
	return (EXIT_SUCCESS);
}

int	init_process_flood(t_map *map)
{
	int		width;
	int		height;

	width = get_width_map(map->map);
	height = get_height_map(map->map);
	map->width = width;
	map->height = height;
	if (expand_map(map, width, height))
	return (ft_error("exanpad map invalid"));
	int	i = -1;
	while (map->dup_map[++i])
		printf("%s\n", map->dup_map[i]);
	if (!flood_fill(map->dup_map, 0, 0))
		return (ft_error("flood fill map invalid"));
	free_matriz(map->dup_map);
	map->dup_map = NULL;
	return (EXIT_SUCCESS);
}
