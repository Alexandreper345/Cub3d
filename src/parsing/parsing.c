/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:05:56 by alda-sil          #+#    #+#             */
/*   Updated: 2025/10/21 22:01:44 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	format_texture(t_map *map)
{
	int	i;

	i = 0;
	if (map->matriz[i] != 'NO' || map->matriz[i] != 'WE' || 
		map->matriz[i] != 'SO' || map->matriz[i] != 'EA')
	{
		//free(matrix) free matriz
		ft_error("argument invalid");
		return (EXIT_FAILURE);
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
		return 	NULL;
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_error("map invalid, because this color invalid");
		return (EXIT_FAILURE);
	}
	free(color);
	color = (r << 16) | (g << 8) | b;
	return color;
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
			map->Floor = convert_color(temp);
			free(temp);
		}
		else if (line[0] == 'C')
		{
			temp = ft_strtrim(line + 1, " ");
			map->Ceiling = convert_color(temp);
			free(temp);
		}
	}
	if (!map->Floor || !map->Ceiling)
	{
		ft_error("map invalid, because not exist color");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parsing(t_map *map)
{
	if (format_texture(map))
		return (EXIT_FAILURE);
	if (get_color(map))
		return (EXIT_FAILURE);

}