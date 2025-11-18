/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:23:12 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 23:39:54 by erocha-l         ###   ########.fr       */
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

int	get_height_map(char **matriz)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((matriz[i][0] != '\n' && matriz[i][0]) && matriz[i][0] != '\0')
	{
		printf("%s",matriz[i]);
		i++;
	}
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

void	get_position_map(char **matriz, t_map *map)
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
				return ;
			}	
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}