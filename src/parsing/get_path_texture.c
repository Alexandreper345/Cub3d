/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:52:46 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/16 21:41:36 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	insert_value_texture(char *line, t_map *map)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1])
	{
		free_matriz(split);
		ft_error("split texture failed");
		return (EXIT_FAILURE);
	}
	if (split[1][ft_strlen(split[1]) - 1] == '\n')
		split[1][ft_strlen(split[1]) - 1] = '\0';
	if (ft_strcmp(split[0], "NO") == 0)
		map->no_path = ft_strdup(split[1]);
	if (ft_strcmp(split[0], "SO") == 0)
		map->so_path = ft_strdup(split[1]);
	if (ft_strcmp(split[0], "WE") == 0)
		map->we_path = ft_strdup(split[1]);
	if (ft_strcmp(split[0], "EA") == 0)
		map->ea_path = ft_strdup(split[1]);
	free_matriz(split);
	return (EXIT_SUCCESS);
}

static int	format_map(char *line, t_map *map)
{
	char	*search_dot;
	int		result;

	search_dot = ft_strrchr(line, '.');
	if (!search_dot)
	{
		ft_error("format invalid");
		return (EXIT_FAILURE);
	}
	result = ft_strcmp(search_dot, ".xpm\n");
	if (result != 0)
	{
		ft_error("format texture invalid");
		return (EXIT_FAILURE);
	}
	insert_value_texture(line, map);
	return (EXIT_SUCCESS);
}

int	get_path_text(t_map *map)
{
	char	*line;
	int		i;

	i = -1;
	while (map->matriz[++i])
	{
		line = map->matriz[i];
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
			if (format_map(line, map))
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
