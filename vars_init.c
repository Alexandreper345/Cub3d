/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:08:42 by erocha-l          #+#    #+#             */
/*   Updated: 2025/11/07 20:45:55 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"


static void init_buffer(t_vars *vars)
{
    printf("Inicializando o buffer de imagem...\n");
    vars->buffer.img_ptr = mlx_new_image(vars->mlx, vars->width, vars->height);
    if (vars->buffer.img_ptr == NULL)
    {
        printf("Erro fatal: mlx_new_image() para o buffer falhou.\n");
        exit(1);
    }
    vars->buffer.addr = mlx_get_data_addr(vars->buffer.img_ptr,
                                        &vars->buffer.bpp,
                                        &vars->buffer.line_len,
                                        &vars->buffer.endian);    
    printf("Buffer inicializado. Endereço (addr): %p\n", vars->buffer.addr);
}

static void init_fps(t_fps *fps)
{
    ft_memset(fps, 0, sizeof(t_fps));
    fps->time = 0;
    fps->oldTime = 0;
    gettimeofday(&fps->timeOfDay, NULL);
    fps->time = fps->timeOfDay.tv_sec;
    fps->frameTime = 0;
    fps->mv = 0;
    fps->rs = 0;
}

void    init_vars(t_vars *vars)
{
    vars->height = 720;
    vars->width = 1080;
    vars->mlx = NULL;
    vars->win = NULL;
    ft_memset(&vars->game, 0, sizeof(t_game));
    ft_memset(&vars->map, 0, sizeof(t_map));
    ft_memset(&vars->player, 0, sizeof(t_player));
    ft_memset(&vars->camera, 0, sizeof(t_camera));
    ft_memset(&vars->map.NO, 0, sizeof(t_texture));
    ft_memset(&vars->map.WE, 0, sizeof(t_texture));
    ft_memset(&vars->map.SO, 0, sizeof(t_texture));
    ft_memset(&vars->map.EA, 0, sizeof(t_texture));
    ft_memset(&vars->buffer, 0, sizeof(t_texture));
    init_fps(&vars->fps);
    vars->player.posX = 7.0; 
    vars->player.posY = 3.0;
    vars->camera.dirX = -1.0;
    vars->camera.dirY = 0.0;
    vars->camera.planeX = 0.0;
    vars->camera.planeY = -0.66;
    vars->camera.height = 720;
}

// only to simulate a parser, it will be substitued for alexandre real parser
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
    i = 0;
    printf("sai do loop\n");
    map->NO_path = "./files/NORTH.xpm";
    map->SO_path = "./files/SOUTH.xpm";
    map->WE_path = "./files/WEST.xpm";
    map->EA_path = "./files/EAST.xpm";
    map->Ceiling_color = 16711680;
    map->Floor_color = 16711680;
    map->width = ft_strlen(map->map[i]);
    map->height = 10;
    map->tex_height = 0;
    map->tex_width = 0;
    close (fd);
    printf("sai aqui do simples parser\n");
}
