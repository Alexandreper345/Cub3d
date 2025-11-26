/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:52:46 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/25 21:59:06 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_file_before_map(char *line)
{
	char **split;

	if ((line[0] == '1' ||  line[0] == '0'))
		return (EXIT_FAILURE);
	split = ft_split(line, ' ');
	if ((ft_strcmp(split[0], "NO") != 0 && ft_strcmp(split[0], "SO") != 0) &&
		(ft_strcmp(split[0], "WE") != 0 && ft_strcmp(split[0], "EA") != 0) &&
		(ft_strcmp(split[0], "F") != 0 && ft_strcmp(split[0], "C") != 0) && line[0] != '\n')
			return (EXIT_FAILURE);
	//free split not create
	return (EXIT_SUCCESS);
}

int get_position_player(char **map , t_player *player)
{
	int 		i;
	int 		j;
	
	i = -1;
	while(map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' ||
				map[i][j] == 'S' || map[i][j] == 'E')
			{
				player->height = i;
				player->width = j;
				return (EXIT_SUCCESS);
			}
		}
	}
	ft_error("the player not exits");
	return (EXIT_FAILURE);
}

int	check_map_valid(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] != 'N') && (map[i][j] != 'S') &&
				(map[i][j] != 'W') && map[i][j] != 'E' &&
				(map[i][j] != '0' && map[i][j] != '1') && map[i][j] != '\n')
				return (EXIT_FAILURE);
			if ((map[i][j] == 'N') || (map[i][j] == 'S') ||
				(map[i][j] == 'W') || (map[i][j] == 'E'))
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_position_map(char **matriz, t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while(matriz[i] && matriz[i][0] != '1')
		i++;
	if (!matriz[i])
		return(ft_error("map not exist"), EXIT_FAILURE);
	count = 0;
	while(matriz[i + count] && matriz[i + count][0] == '1')
		count++;
	map->map = malloc(sizeof(char *) * (count + 1));
	if (!map->map)
		return (ft_error("malloc error"), EXIT_FAILURE);
	j = -1;
	while (++j < count)
		map->map[j] = ft_strdup(matriz[i + j]);
	map->map[j] = NULL;
	if (check_map_valid(map->map))
		return (ft_error("map invalid"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
