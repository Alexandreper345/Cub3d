/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:23:12 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 21:44:55 by alda-sil         ###   ########.fr       */
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
