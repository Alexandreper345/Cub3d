/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 21:22:43 by erocha-l          #+#    #+#             */
/*   Updated: 2026/01/07 21:19:19 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void	free_mlx(t_vars *vars)
{
	if (vars->map->so.img_ptr)
		mlx_destroy_image(vars->mlx, vars->map->so.img_ptr);
	if (vars->map->ea.img_ptr)
		mlx_destroy_image(vars->mlx, vars->map->ea.img_ptr);
	if (vars->map->we.img_ptr)
		mlx_destroy_image(vars->mlx, vars->map->we.img_ptr);
	if (vars->map->no.img_ptr)
		mlx_destroy_image(vars->mlx, vars->map->no.img_ptr);
	if (vars->buffer.img_ptr)
		mlx_destroy_image(vars->mlx, vars->buffer.img_ptr);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
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
	if (vars->map->dup_map)
		free_matriz(vars->map->dup_map);
	if (vars->map->map)
		free_matriz(vars->map->map);
	if (vars->map->matriz)
		free_matriz(vars->map->matriz);
	if (vars->map->ea_path)
		free(vars->map->ea_path);
	if (vars->map->no_path)
		free(vars->map->no_path);
	if (vars->map->so_path)
		free(vars->map->so_path);
	if (vars->map->we_path)
		free(vars->map->we_path);
	if (vars->map)
		free(vars->map);
	if (vars->player)
		free(vars->player);
	if (vars)
		free(vars);
}
