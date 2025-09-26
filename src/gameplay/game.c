/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:02:09 by erocha-l          #+#    #+#             */
/*   Updated: 2025/09/25 20:04:32 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int game(t_vars *vars)
{
    printf("cheguei até aqui\n");
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, 1080, 720, "Hello world!");
    if (vars->win == NULL)
        free_mlx(vars->mlx);
    gameplay(vars);
    mlx_loop(vars->mlx);
    return (0);
}