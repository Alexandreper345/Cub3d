/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:05:56 by alda-sil          #+#    #+#             */
/*   Updated: 2026/01/13 21:45:43 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	exist_textures_and_color(char *line, int flag)
{
	char	**split;

	split = ft_split(line, ' ');
	if (ft_strcmp(split[0], "NO") == 0 || ft_strcmp(split[0], "SO") == 0)
		flag++;
	if (ft_strcmp(split[0], "WE") == 0 || ft_strcmp(split[0], "EA") == 0)
		flag++;
	if (line[0] == 'F' || line[0] == 'C')
		flag++;
	free_matriz(split);
	return (flag);
}

int	check_config_info(t_map *map)
{
	int		i;
	int		flag;
	char	*line;

	i = -1;
	flag = 0;
	while (map->matriz[++i])
	{
		line = map->matriz[i];
		if (check_file_before_map(line))
			return (ft_error("invalid struct map"));
		flag = exist_textures_and_color(line, flag);
		if (flag == 6)
			return (EXIT_SUCCESS);
	}
	i = -1;
	return (EXIT_SUCCESS);
}

int	convert_color(char *rgb)
{
	char	**color;
	int		r;
	int		g;
	int		b;

	rgb = switch_newline(rgb);
	color = ft_split(rgb, ',');
	if (!color[0] || !color[1] || !color[2] || color[3])
	{
		free_matriz(color);
		return (-1);
	}
	if (is_number(color[0]) || is_number(color[1]) || is_number(color[2]))
	{
		free_matriz(color);
		return (-1);
	}
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	free_matriz(color);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(t_map *map)
{
	int		i;
	char	*temp;

	i = -1;
	while (map->matriz[++i])
	{
		if (map->matriz[i][0] == 'F')
		{
			temp = ft_strtrim(map->matriz[i] + 1, " ");
			map->floor_color = convert_color(temp);
			free(temp);
		}
		else if (map->matriz[i][0] == 'C')
		{
			temp = ft_strtrim(map->matriz[i] + 1, " ");
			map->ceiling_color = convert_color(temp);
			free(temp);
		}
	}
	if (map->floor_color == -1 || map->ceiling_color == -1)
		return (ft_error("map invalid, because invalid color"));
	return (EXIT_SUCCESS);
}

int	parsing(t_map *map, t_vars *vars_main)
{
	if (check_file(map->matriz))
		return (EXIT_FAILURE);
	if (check_config_info(map) || get_color(map))
		return (EXIT_FAILURE);
	if (get_path_text(map))
		return (EXIT_FAILURE);
	if (get_position_map(map->matriz, map) || get_position_player(map->map,
			vars_main))
		return (EXIT_FAILURE);
	if (check_duplacate_map(map->map) || init_process_flood(map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
