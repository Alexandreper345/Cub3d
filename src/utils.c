/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:23:12 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/26 21:19:45 by alda-sil         ###   ########.fr       */
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
	int		i;
	int		j;

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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}