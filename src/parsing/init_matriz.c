/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matriz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:09:32 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/11 02:27:28 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


static int check_is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' '  || line[i] == '\n'))
	{
		i++;
	}
	if (line[i] == '1' || line[i] == '0') // not sure if this will work
		return(0);
	return(1);
	
}

void recreate_matriz(t_vars *vars, char *path)  // need to free oldmatriz
{
	int		index;
	int		fd;
	size_t	max;
	char	*line;
	
	index = 0;
	max = 0;
	fd = open(path, O_RDWR);
	if (!fd)
		return ; 
	line = get_next_line(fd);
	if (line && check_is_map_line(line) == 0)
		max = ft_strlen(line);
	while (line != NULL)
	{
		if (check_is_map_line(line) == 0)
			vars->map->matriz[index] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		if (line && ft_strlen(line) > max && check_is_map_line(line) == 0)
			max = ft_strlen(line);
		index++;
	}
	printf("aqui está width %d\n", (int)max);
	vars->map->width = (int)max;
}

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
	if (fd == -1)
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
