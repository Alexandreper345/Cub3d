/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:52:46 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/16 20:22:15 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

int	save_map(char **matriz, int count, int i, t_map *map)
{
	int	len;
	int	j;
	int	res;

	j = -1;
	len = 0;
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
	return (EXIT_SUCCESS);
}

int	check_invalid_caracter(char **matriz, int end, int i, t_map *map)
{
	int	count;
	int	res;

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
	if (save_map(matriz, count, i, map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_position_map(char **matriz, t_map *map)
{
	int	i;
	int	j;
	int	end;

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
	if (check_invalid_caracter(matriz, end, i, map))
		return (EXIT_FAILURE);
	if (check_map_valid(map->map))
		return (ft_error("map invalid"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
