/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:02:09 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/16 21:13:25 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_buffer(t_vars *vars)
{
	vars->buffer.img_ptr = mlx_new_image(vars->mlx, vars->width, vars->height);
	if (vars->buffer.img_ptr == NULL)
	{
		printf("Erro : mlx_new_image() para o buffer falhou.\n");
		exit(1);
	}
	vars->buffer.addr = mlx_get_data_addr(vars->buffer.img_ptr,
			&vars->buffer.bpp, &vars->buffer.line_len, &vars->buffer.endian);
}

int	game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1080, 720, "Hello world!");
	if (vars->win == NULL)
	{
		free_mlx(vars->mlx);
		return (0);
	}
	game_settings(vars);
	init_buffer(vars);
	mlx_hook(vars->win, 2, 1L << 0, walk, vars);
	mlx_loop_hook(vars->mlx, gameplay, vars);
	mlx_loop(vars->mlx);
	free_mlx(vars);
	return (0);
}
