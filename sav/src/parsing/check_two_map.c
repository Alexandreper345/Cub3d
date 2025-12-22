/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_two_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:05:17 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/22 19:42:48 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_duplacate_map(char **map)
{
	int	in_map;
	int	finish_map;
	int	i;

	in_map = 0;
	finish_map = 0;
	i = -1;
	while (map[++i])
	{
		if (ft_strchr(" 01", map[i][0]))
		{
			if (finish_map)
				return (EXIT_FAILURE);
			in_map = 1;
		}
		else if (in_map && map[i][0] == '\n')
			finish_map = 1;
	}
	return (EXIT_SUCCESS);
}
