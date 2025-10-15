/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:57:40 by alda-sil          #+#    #+#             */
/*   Updated: 2025/10/14 19:35:16 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

typedef struct s_player
{
	int	width;
	int	height;
} t_player;

typedef	struct s_map
{
	char 		**matriz;
	char		*NO_path;
	char		*SO_path;
	char		*WE_path;
	char		*EA_path;
	void		*NO;
	void		*SO;
	void		*WE;
	void		*EA;
	int			height;
	int			width;
	char		*Floor;
	char		*Ceiling;
} t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		*map;
} t_vars;

void	ft_error(char *str);
void	free_mlx(t_vars *vars);
void	free_and_exit(t_vars *vars);
void    init_vars(t_vars *vars, char *map_path);
void	gameplay(t_vars *vars);
int		game(t_vars *vars);
int		escape(int keycode, t_vars *vars);
int		x_button(t_vars *vars);
int		check_file_path(int argc, char **argv);
int		init_matriz(t_map *map, char *path);
int		parsing(t_map *map);

#endif