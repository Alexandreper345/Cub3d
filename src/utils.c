/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:23:12 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/09 20:40:31 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_height_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		return (EXIT_FAILURE);
	while (map[i] != NULL)
		i++;
	return (i);
}

int	get_width_map(char **matriz)
{
	int	i;
	int	max;
	int	size;

	i = -1;
	max = 0;
	while (matriz[++i])
	{
		size = len(matriz[i]);
		if (size > max)
			max = size;
	}
	return (max);
}

int	params_map(char **split, char *map)
{
	if (ft_strcmp(split[0], "NO") == 0 || ft_strcmp(split[0], "SO") == 0)
		return (EXIT_SUCCESS);
	else if (ft_strcmp(split[0], "WE") == 0 || ft_strcmp(split[0], "EA") == 0)
		return (EXIT_SUCCESS);
	else if (ft_strcmp(split[0], "F") == 0 || ft_strcmp(split[0], "C") == 0)
		return (EXIT_SUCCESS);
	else if (map[0] == '\n' || map[0] == ' ' || map[0] == '\t')
		return (EXIT_SUCCESS);
	else if (map[0] == '1')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	check_file(char **map)
{
	int		i;
	int		flag;
	char	**split;

	i = 0;
	flag = 0;
	while (map[i])
	{
		split = ft_split(map[i], ' ');
		ft_strtrim(map[i], " \t");
		if (map[i][0] == '1' && flag == 0)
		{
			if (check_map_valid(&map[i]))
				return (EXIT_FAILURE);
			flag = 1;
		}
		if (params_map(split, map[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
