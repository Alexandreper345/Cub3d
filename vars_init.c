/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:08:42 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/16 20:28:23 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

static void	init_fps(t_fps *fps)
{
	ft_memset(fps, 0, sizeof(t_fps));
	fps->time = 0;
	fps->old_time = 0;
	gettimeofday(&fps->timeofday, NULL);
	fps->time = fps->timeofday.tv_sec;
	fps->frame_time = 0;
	fps->mv = 0;
	fps->rs = 0;
}

/*void    init_vars(t_vars *vars)
{
	int		fd;
	char	*line;
	int		i;

	vars->height = 720;
	vars->width = 1080;
	vars->mlx = NULL;
	vars->win = NULL;
	ft_memset(&vars->map, 0, sizeof(t_map));
	ft_memset(&vars->player, 0, sizeof(t_player));
	ft_memset(&vars->camera, 0, sizeof(t_camera));
	ft_memset(&vars->map.no, 0, sizeof(t_texture));
	ft_memset(&vars->map.we, 0, sizeof(t_texture));
	ft_memset(&vars->map.so, 0, sizeof(t_texture));
	ft_memset(&vars->map.ea, 0, sizeof(t_texture));
	ft_memset(&vars->buffer, 0, sizeof(t_texture));
	init_fps(&vars->fps);
	vars->player.posx = 7.0;
	vars->player.posy = 3.0;
	vars->camera.dir_x = -1.0;
	vars->camera.dir_y = 0.0;
	vars->camera.plane_x = 0.0;
	vars->camera.plane_y = -0.66;
	vars->camera.height = 720;
}*/
// only to simulate a parser, it will be substitued for alexandre real parser
/*
void	simple_parser(t_map *map, char *path)
{
	fd = open(path, O_RDWR);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map->matriz = ft_calloc(sizeof(char *), (i + 1));
	i = 0;
	close(fd);
	fd = open(path, O_RDWR);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->matriz[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	i = 0;
	printf("sai do loop\n");
	map->no_path = "./files/noRTH.xpm";
	map->so_path = "./files/soUTH.xpm";
	map->we_path = "./files/weST.xpm";
	map->ea_path = "./files/eaST.xpm";
	map->ceiling_color = 255;
	map->floor_color = 65280;
	map->width = ft_strlen(map->matriz[i]);
	map->height = 10;
	map->tex_height = 0;
	map->tex_width = 0;
	close(fd);
	printf("sai aqui do simples parser\n");
}
*/