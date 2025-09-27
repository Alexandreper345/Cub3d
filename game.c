/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:02:09 by erocha-l          #+#    #+#             */
/*   Updated: 2025/09/27 10:08:31 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int game(t_vars *vars)
{
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, 1080, 720, "Hello world!");
    if (vars->win == NULL)
        free_mlx(vars->mlx);
    game_settings(vars);
    mlx_loop(vars->mlx);
    return (0);
}
