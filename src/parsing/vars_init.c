/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:08:42 by erocha-l          #+#    #+#             */
/*   Updated: 2025/09/25 20:40:52 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_player    init_player(t_player *player)
{
	player->height = 0;
	player->width = 0;
}

t_map   init_map(t_map *map)
{
	map->NO_path = files/NORTH.png;
	map->SO_path = files/SOUTH.png;
	map->WE_path = files/WEST.png;
	map->EA_path = files/EAST.png;
	map->height = 0;
	map->width = 0;
}

void    init_vars(t_vars *vars)
{
	t_player	*player;
	t_map		*map;

	init_player(player);
	init_map(map);
	vars->mlx = NULL;
	vars->win = NULL;
}

void    simple_parser(t_map *map, char *path)
{
	int     fd;
	char    *line;
	int     i;

	fd = open(path, O_RDWR);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map->map = ft_calloc(sizeof(char *), (i + 1));
	i = 0;
	close(fd);
	fd = open(path, O_RDWR);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close (fd);
}
