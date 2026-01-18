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

int	check_duplacate_map(char **map, int i, int count)
{
	int	k;
	int	res;

	k = i + count;
	while (map[k])
	{
		res = is_line_map(map[k]);
		if (res == 1)
			return (ft_error("duplicate map"));
		k++;
	}
	return (EXIT_SUCCESS);
}
