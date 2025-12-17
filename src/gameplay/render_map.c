/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:02:57 by erocha-l          #+#    #+#             */
/*   Updated: 2025/12/16 20:22:15 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	create_texture(t_vars *vars, t_texture *tex, char *path)
{
	t_map	*map;

	map = vars->map;
	printf("aqui está o path: %s\n", path);
	tex->img_ptr = mlx_xpm_file_to_image(vars->mlx, path, &map->tex_width,
			&map->tex_height);
	if (tex->img_ptr == NULL)
	{
		printf("erro ao carregar textura\n");
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->line_len,
			&tex->endian);
	tex->width = map->tex_width;
	tex->height = map->tex_height;
}

static void	convert_textures_to_img(t_vars *vars)
{
	t_map	*map;

	map = vars->map;
	map->tex_width = 256;
	map->tex_height = 256;
	create_texture(vars, &map->no, map->no_path);
	create_texture(vars, &map->ea, map->ea_path);
	create_texture(vars, &map->so, map->so_path);
	create_texture(vars, &map->we, map->we_path);
}

void	game_settings(t_vars *vars)
{
	convert_textures_to_img(vars);
	mlx_hook(vars->win, 17, 1L << 19, x_button, vars);
}
