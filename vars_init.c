/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:08:42 by erocha-l          #+#    #+#             */
/*   Updated: 2025/10/15 16:51:59 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"


static void init_buffer(t_vars *vars)
{
    // Imprime uma mensagem para sabermos que a função foi chamada.
    printf("Inicializando o buffer de imagem...\n");

    // 1. Pede para a MiniLibX criar uma nova imagem em branco na memória
    //    com a mesma largura e altura da nossa janela.
    //    O ponteiro para essa imagem é guardado em 'img_ptr'.
    vars->buffer.img_ptr = mlx_new_image(vars->mlx, vars->width, vars->height);

    // 2. VERIFICAÇÃO DE ERRO: Se a mlx não conseguir criar a imagem, o ponteiro
    //    será nulo. Precisamos parar o programa para evitar um segfault.
    if (vars->buffer.img_ptr == NULL)
    {
        printf("Erro fatal: mlx_new_image() para o buffer falhou.\n");
        // Aqui você chamaria uma função para limpar a memória e sair.
        exit(1);
    }

    // 3. Pega as informações vitais sobre a imagem que acabamos de criar.
    //    A mlx vai preencher o endereço dos pixels (addr), os bits por pixel (bpp),
    //    o tamanho da linha (line_len) e o endian.
    vars->buffer.addr = mlx_get_data_addr(vars->buffer.img_ptr,
                                        &vars->buffer.bpp,
                                        &vars->buffer.line_len,
                                        &vars->buffer.endian);
    
    // DEBUG: Imprime o endereço para confirmar que não é nulo.
    printf("Buffer inicializado. Endereço (addr): %p\n", vars->buffer.addr);
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
    vars->player.posX = 1; 
    vars->player.posY = 5;
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
    map->Floor[0] = 220;
    map->Floor[1] = 100;
    map->Floor[2] = 0;
    map->Ceiling[0] = 225;
    map->Ceiling[1] = 30;
    map->Ceiling[2] = 0;
    map->width = ft_strlen(map->map[i]);
    map->height = 10;
    map->tex_height = 0;
    map->tex_width = 0;
    close (fd);
    printf("sai aqui do simples parser\n");
}
