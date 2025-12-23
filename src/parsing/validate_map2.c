/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:59:36 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/22 22:38:23 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_file_before_map(char *line)
{
	char	**split;

	if ((line[0] == '1' || line[0] == '0'))
		return (EXIT_FAILURE);
	split = ft_split(line, ' ');
	if ((ft_strcmp(split[0], "NO") != 0 && ft_strcmp(split[0], "SO") != 0)
		&& (ft_strcmp(split[0], "WE") != 0 && ft_strcmp(split[0], "EA") != 0)
		&& (ft_strcmp(split[0], "F") != 0 && ft_strcmp(split[0], "C") != 0)
		&& line[0] != '\n' && line[0] != ' ' && line[0] != '\t')
		return (EXIT_FAILURE);
	free_matriz(split);
	return (EXIT_SUCCESS);
}

int	get_position_player(char **map, t_vars *vars_main)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S'
				|| map[i][j] == 'E')
			{
				vars_main->player->posy = (i + 0.5);
				vars_main->player->posx = (j + 0.5);
				star_game(map, vars_main, i, j);
				return (EXIT_SUCCESS);
			}
		}
	}
	return (ft_error("the player not exits"));
}

void	star_game(char **map, t_vars *vars, int i, int j)
{
	if (map[i][j] == 'N')
	{
		vars->camera.dir_y = -1;
		vars->camera.plane_x = 0.66;
	}
	else if (map[i][j] == 'S')
	{
		vars->camera.dir_y = 1;
		vars->camera.plane_x = -0.66;
	}
	else if (map[i][j] == 'E')
	{
		vars->camera.dir_x = 1;
		vars->camera.plane_y = 0.66;
	}
	else if (map[i][j] == 'W')
	{
		vars->camera.dir_x = -1;
		vars->camera.plane_y = -0.66;
	}
}
