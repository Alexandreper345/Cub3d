/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:52:46 by alda-sil          #+#    #+#             */
/*   Updated: 2025/11/04 21:23:09 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void get_position_player(char **map)
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
			if (map[i][j])
			{
				player->height = i;
				player->width = j;
			}
		}
	}
}