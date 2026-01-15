/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:23:12 by alda-sil          #+#    #+#             */
/*   Updated: 2026/01/14 22:15:18 by alda-sil         ###   ########.fr       */
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
	else if (map[0] == '\n' || map[0] == ' ')
		return (EXIT_SUCCESS);
	else if (map[0] == '1')
		return (EXIT_SUCCESS);
	return (ft_error("content invalid: caracter invalid"));
}

int	check_file(char **map)
{
	int		i;
	int		flag;
	char	*temp;
	char	**split;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		split = ft_split(map[i], ' ');
		temp = ft_strtrim_cub(map[i], " ");
		if (*temp == '\0')
			return (free_temp_and_split(split, temp));
		if (check_error_in_check_file(split, temp, map, i))
			return (EXIT_FAILURE);
		if (temp[0] == '1' && flag == 0)
		{
			if (check_map_valid(&map[i]))
				return (return_failure(split, temp, ""));
			flag = 1;
		}
		free_temp_and_split(split, temp);
	}
	return (EXIT_SUCCESS);
}
