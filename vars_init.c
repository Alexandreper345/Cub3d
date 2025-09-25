/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erick <erick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:08:42 by erocha-l          #+#    #+#             */
/*   Updated: 2025/09/25 10:39:04 by erick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void    init_vars(t_vars *vars)
{
    vars->height = 0;
    vars->width = 0;
    vars->mlx = NULL;
    vars->win = NULL;
    ft_memset(&vars->game, 0, sizeof(t_game));
    ft_memset(&vars->map, 0, sizeof(t_map));
    ft_memset(&vars->player, 0, sizeof(t_player));
}

void    simple_parser(t_map *map, char *path)
{
    int     fd;
    char    *line;
    int     i;

    fd = open(path, O_RDWR);
    line = get_next_line(fd);
    i = 0;
    while (line != NULL)
    {
        free(line);
        i++;
        line = get_next_line(fd);
    }
    map->map = ft_calloc(sizeof(char *), (i + 1));
    i = 0;
    close(fd);
    fd = open(path, O_RDWR);
    line = get_next_line(fd);
    while (line != NULL)
    {
        map->map[i] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    map->NO_path = NULL;
    map->SO_path = NULL;
    map->WE_path = NULL;
    map->EA_path = NULL;
    map->NO = NULL;
    map->SO = NULL;
    map->WE = NULL;
    map->EA = NULL;
    map->Floor[0] = 220;
    map->Floor[1] = 100;
    map->Floor[2] = 0;
    map->Ceiling[0] = 225;
    map->Ceiling[1] = 30;
    map->Ceiling[2] = 0;
    close (fd);
}
