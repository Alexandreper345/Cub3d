/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:02:05 by erocha-l          #+#    #+#             */
/*   Updated: 2025/09/25 12:10:36 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int escape(int keycode, t_vars *vars)
{
    if (keycode == XK_Escape)
        free_and_exit(vars);
}

int x_button(t_vars *vars)
{
    free_and_exit(vars);
}

int walk(t_vars *vars)
{
    
}