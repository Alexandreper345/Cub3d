/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:02:09 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/09 21:55:30 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_buffer(t_vars *vars)
{
	printf("Inicializando o buffer de imagem...\n");
	vars->buffer.img_ptr = mlx_new_image(vars->mlx, vars->width, vars->height);
	if (vars->buffer.img_ptr == NULL)
	{
		printf("Erro fatal: mlx_new_image() para o buffer falhou.\n");
		exit(1);
	}
	vars->buffer.addr = mlx_get_data_addr(vars->buffer.img_ptr,
			&vars->buffer.bpp, &vars->buffer.line_len, &vars->buffer.endian);
	printf("Buffer inicializado. Endereço (addr): %p\n", vars->buffer.addr);
}

int	game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1080, 720, "Hello world!");
	if (vars->win == NULL)
	{
		printf("entrei aqui no free mlx\n");
		free_mlx(vars->mlx);
	}
	game_settings(vars);
	init_buffer(vars);
	mlx_hook(vars->win, 2, 1L << 0, walk, vars);
	printf("fui até aqui 1\n");
	mlx_loop_hook(vars->mlx, gameplay, vars);
<<<<<<< HEAD
	printf("fui até aqui 2 %x \n", vars->mlx);
	while (1)
	{
		
	}
	
=======
	mlx_loop(vars->mlx);
>>>>>>> 04cd60cb5769b617fe4cf34de56a4f1b91e8fc2b
	return (0);
}