/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:52:46 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/18 21:42:42 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_file_before_map(char *line)
{
	char **split;

	if ((line[0] == '1' ||  line[0] == '0'))
		return (EXIT_FAILURE);
	split = ft_split(line, ' ');
	if ((ft_strncmp(split[0], "NO", 2) != 0 && ft_strcmp(split[0], "SO", 2) != 0) &&
		(ft_strcmp(split[0], "WE", 2) != 0 && ft_strcmp(split[0], "EA", 2) != 0) &&
		(line[0] == 'F' || line[0] == 'C') && line[0] != ' ')
			return (EXIT_FAILURE);
	//free split not create
	return (flag);
		
}

int get_position_player(char **map)
{
	int 		i;
	int 		j;
	t_player	*player;
	
	i = -1;
	while(map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if (map[i][j] == 'P')
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

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((ft_strncmp(map[i][j], "NO", 2) != 0 && ft_strcmp(map[i][j], "SO", 2) != 0) &&
				(ft_strcmp(map[i][j], "WE", 2) != 0 && ft_strcmp(map[i][j], "EA", 2) != 0) &&
				(map[i][j] != '0' && map[i][j] == '1'))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	get_position_map(char **matriz, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while(matriz[++i])
	{
		j = 0;
		if(matriz[i][j] == '1')
			if (matriz[i][j + 1] == '1')
			{
				map->map = matriz[i][j];
				if (check_map_valid(map->map))
				{
					ft_error("charecter map invalid");
					return (EXIT_FAILURE);
				}
				return(EXIT_SUCCESS);
			}	
	}
	return (EXIT_FAILURE);
}
