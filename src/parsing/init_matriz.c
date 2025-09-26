/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matriz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:09:32 by alda-sil          #+#    #+#             */
/*   Updated: 2025/09/25 21:41:11 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int	is_malloc_in_pointe_x(t_map	*map)
{
	int	index;

	index = 0;
	while (index < map->y)
	{
		map->matriz[index] = ft_calloc(sizeof(char), map->x + 1);
		if (map->matriz[index] == NULL)
		{
			//frees(map->matriz, map->y); not yet create free free
			ft_error("failure in calloc map_x");
			return (EXIT_FAILURE);
		}
		index++;
	}
	return (EXIT_SUCCESS);
}

int	is_malloc_in_pointer_y(t_map *map, char *path)
{
	int     fd;
	char    *line;

	fd = open(path, O_RDWR);
	line = get_next_line(fd);
	map->height = ft_strlen(line);
	while (line != NULL)
	{
		free(line);
		if (map->height < ft_strlen(line))
			map->height = ft_strlen(line);
		line = get_next_line(fd);
	}
	map->matriz = (char **)ft_calloc(sizeof(char *), ((map->height * 2) + 1));
	if (!map->matriz)
	{
		ft_error("failure in calloc map_y");
		return (EXIT_FAILURE);
	}
	if (is_malloc_in_pointe_x(map))
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}
