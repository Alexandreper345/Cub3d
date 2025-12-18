/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 21:22:43 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/16 22:21:20 by alda-sil         ###   ########.fr       */
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
	mlx_destroy_image(vars->mlx, vars->map->so.img_ptr);
	mlx_destroy_image(vars->mlx, vars->map->ea.img_ptr);
	mlx_destroy_image(vars->mlx, vars->map->we.img_ptr);
	mlx_destroy_image(vars->mlx, vars->map->no.img_ptr);
	mlx_destroy_image(vars->mlx, vars->buffer.img_ptr);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

void	free_matriz(char **matriz)
{
	int	i;

	i = -1;
	while (matriz[++i])
		free(matriz[i]);
	free(matriz);
}

void	free_all(t_vars *vars)
{
	free(vars->map->so_path);
	free(vars->map->ea_path);
	free(vars->map->we_path);
	free(vars->map->no_path);
	free_map(vars->map->map);
	free(vars->player);
	free(vars->map);
	free(vars);
}
