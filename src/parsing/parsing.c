/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:05:56 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/12 20:45:44 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	exist_textures_and_color(char *line, int flag)
{
char **split;

	split = ft_split(line, ' ');
	if (ft_strcmp(split[0], "NO") == 0 || ft_strcmp(split[0], "SO") == 0)
		flag++;;
	if (ft_strcmp(split[0], "WE") == 0 || ft_strcmp(split[0], "EA") == 0)
		flag++;;
	if (line[0] == 'F' || line[0] == 'C')
		flag++;
	//free split not create
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
		if (line[0] == '1' ||  line[0] == '0')
		{
			//free(matrix) free matriz
			ft_error("invalid struct map");
			return (EXIT_FAILURE);
		}
		flag = exist_textures_and_color(line, flag);
		if (flag == 6)
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	convert_color(char *rgb)
{
	char	**color;
	int		r;
	int		g;
	int		b;

	color = ft_split(rgb, ',');
	if (!color)
		return 	(EXIT_FAILURE);
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_error("map invalid, because this color invalid");
		return (EXIT_FAILURE);
	}
	free(color);
	return ((r << 16) | (g << 8) | b);
}


int	get_color(t_map *map)
{
	int		i;
	char	*line;
	char	*temp;

	i = -1;
	while (map->matriz[++i])
	{
		line = map->matriz[i];
		if (line[0] == 'F')
		{
			temp = ft_strtrim(line + 1, " ");
			map->floor = convert_color(temp);
			free(temp);
		}
		else if (line[0] == 'C')
		{
			temp = ft_strtrim(line + 1, " ");
			map->ceiling = convert_color(temp);
			free(temp);
		}
	}
	if (!map->floor || !map->ceiling)
	{
		ft_error("map invalid, because not exist color");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parsing(t_map *map)
{
	if (check_config_info(map))
		return (EXIT_FAILURE);
	if (get_color(map))
		return (EXIT_FAILURE);
	if (init_process_flood(map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}