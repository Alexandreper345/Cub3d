/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 21:22:43 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/02 22:04:23 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_mlx(t_vars *vars)
{
	mlx_destroy_display(vars->win);
	free(vars->win);
}

void	free_and_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars->map->matriz);
	exit(0);
}

void	free_matriz(char **matriz)
{
	int	i;

	i = -1;
	while (matriz[++i])
		free(matriz[i]);
	free(matriz);
}
