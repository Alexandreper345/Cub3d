/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:52:46 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/10 22:07:38 by alda-sil         ###   ########.fr       */
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
	return (EXIT_SUCCESS);
}

void	star_game(char **map, t_vars *vars, int i, int j)
{
	if (map[i][j] == 'N')
	{
		vars->camera.dirX = 0;
		vars->camera.dirY = -1;
		vars->camera.planeX = 0.66;
		vars->camera.planeY = 0;
	}
	else if (map[i][j] == 'S')
	{
		vars->camera.dirX = 0;
		vars->camera.dirY = 1;
		vars->camera.planeX = -0.66;
		vars->camera.planeY = 0;
	}
	else if (map[i][j] == 'E')
	{
		vars->camera.dirX = 1;
		vars->camera.dirY = 0;
		vars->camera.planeX = 0;
		vars->camera.planeY = 0.66;
	}
	else if (map[i][j] == 'W')
	{
		vars->camera.dirX = -1;
		vars->camera.dirY = 0;
		vars->camera.planeX = 0;
		vars->camera.planeY = -0.66;
	}
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
				vars_main->player->posY = i;
				vars_main->player->posX = j;
				star_game(map,vars_main, i, j);
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
			if ((map[i][j] != 'N') && (map[i][j] != 'S') && (map[i][j] != 'W')
				&& map[i][j] != 'E' && (map[i][j] != '0' && map[i][j] != '1')
				&& map[i][j] != '\n')
				return (EXIT_FAILURE);
			if ((map[i][j] == 'N') || (map[i][j] == 'S') || (map[i][j] == 'W')
				|| (map[i][j] == 'E'))
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_line_map(char *line)
{
	int	i;
	int	found_valid;

	found_valid = 0;
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	while (line[i] && line[i] != '\n' && line[i] != '\r')
	{
		if (!ft_strchr(" 01NSEW", line[i]))
			return (-1);
		found_valid = 1;
		i++;
	}
	return (found_valid);
}

int	get_position_map(char **matriz, t_map *map)
{
	int	i;
	int	j;
	int	count;
	int	res;
	int	end;
	int	len;

	i = 0;
	end = 0;
	while (matriz[i] && !end)
	{
		j = 0;
		while (matriz[i][j] == ' ' || matriz[i][j] == '\t')
			j++;
		if (matriz[i][j] == '1')
			end = 1;
		else
			i++;
	}
	if (!matriz[i])
		return (ft_error("map not exist"), EXIT_FAILURE);
	count = 0;
	while (matriz[i + count] && end == 1)
	{
		res = is_line_map(matriz[i + count]);
		if (res == -1)
			return (ft_error("invalid character in map"), EXIT_FAILURE);
		else if (res == 0)
			end = 0;
		else
			count++;
	}
	map->map = malloc(sizeof(char *) * (count + 1));
	if (!map->map)
		return (ft_error("malloc error"), EXIT_FAILURE);
	j = -1;
	while (++j < count)
	{
		res = 0;
		while (matriz[i + j][res] == ' ' || matriz[i + j][res] == '\t')
			res++;
		map->map[j] = ft_strdup(&matriz[i + j][res]);
		len = ft_strlen(map->map[j]);
		if (len > 0 && map->map[j][len - 1] == '\n')
			map->map[j][len - 1] = '\0';
	}
	map->map[j] = NULL;
	if (check_map_valid(map->map))
		return (ft_error("map invalid"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
