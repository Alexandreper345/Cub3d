/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:52:46 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/11 21:48:32 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int get_position_player(char **map)
{
	int 		i;
	int 		j;
	t_player	*player;
	
	i = -1;
	while(map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				player->height = i;
				player->width = j;
				return (EXIT_SUCCESS);
			}
		}
	}
	ft_error("the player not exits");
	return (EXIT_FAILURE);
}