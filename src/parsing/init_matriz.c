/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matriz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:09:32 by alda-sil          #+#    #+#             */
/*   Updated: 2026/01/14 20:38:07 by alda-sil         ###   ########.fr       */
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
	close(fd);
	return (EXIT_SUCCESS);
}

int	malloc_in_pointer_y(t_map *map, char *line, int fd, char *path)
{
	int		height;
	t_map	*lines;

	(void) lines;
	height = 0;
	while (line != NULL)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	map->height = height;
	map->matriz = (char **)ft_calloc((height) + 1, sizeof(char *));
	if (!map->matriz)
		return (ft_error("failure in calloc mapy"));
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
	if (fd == -1)
		return (ft_error("is fd failed"));
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_error("the file is NULL"));
	if (malloc_in_pointer_y(map, line, fd, path))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
