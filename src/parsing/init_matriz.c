/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matriz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:09:32 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/11 22:07:20 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_malloc_in_pointe_x(t_map	*map, char *path)
{
	int		index;
	int		fd;
	char	*line;

	index = 0;
	fd = open(path, O_RDWR);
	if (!fd)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->matriz[index] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		index++;
	}
	return (EXIT_SUCCESS);
}

int	malloc_in_pointer_y(t_map *map, char *line, int fd, char *path)
{
	int		height;
	t_map	*lines;

	lines = NULL;
	height = 0;
	while (line != NULL)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	map->height = height;
	map->matriz = (char **)ft_calloc((height) + 1,sizeof(char *));
	if (!map->matriz)
	{
		ft_error("failure in calloc map_y");
		free_matriz(map->matriz);
		return (EXIT_FAILURE);
	}
	if (is_malloc_in_pointe_x(map, path))
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

int	init_matriz(t_map *map, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDWR);
	if (fd ==   -1)
	{
		ft_error("is fd failed");
		return (EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_error("the content map is NULL");
		return (EXIT_FAILURE);
	}
	if (malloc_in_pointer_y(map, line, fd, path))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);	
}
