/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:02:09 by erocha-l          #+#    #+#             */
/*   Updated: 2025/11/13 18:00:40 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

int game(t_vars *vars)
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
    mlx_hook(vars->win, 2, 1L<<0, walk, vars); // create enum
    mlx_loop_hook(vars->mlx ,gameplay, vars);
    mlx_loop(vars->mlx);
    return (0);
}
