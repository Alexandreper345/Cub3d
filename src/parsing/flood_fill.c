/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:25:52 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/05 21:50:22 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	flood_fill(char **matriz)
{

}




char	**copy_matriz(int height, int width)
{
	char	**copy_matriz;
	int		i;
	int		j;

	copy_matriz = (char **)malloc(sizeof(char *) * height + 3);
	if (!copy_matriz)
		return (NULL);
	i = -1;
	while (++i < height + 2)
	{
		copy_matriz[i] = (char *)malloc(sizeof(char) * width + 3);
		if (!copy_matriz)
			return (NULL);
		j = -1;
		while (++j < width + 2)
			copy_matriz[i][j] = 'x';
		copy_matriz[i][j] = '\0';
	}
	return (copy_matriz);
}



int	init_process_flood(t_map *map)
{
	int	width;
	int	height;

	width = get_width_map(map->matriz);
	height = get_height_map(map->matriz);
}