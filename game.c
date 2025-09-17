/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-17 22:02:09 by erocha-l          #+#    #+#             */
/*   Updated: 2025-09-17 22:02:09 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int game(t_vars *vars)
{
    printf("cheguei até aqui\n");
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Hello world!");
    mlx_loop(vars->mlx);
    return (0);
}