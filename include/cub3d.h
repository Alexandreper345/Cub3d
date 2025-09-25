/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:57:40 by alda-sil          #+#    #+#             */
/*   Updated: 2025/09/25 12:52:49 by erocha-l         ###   ########.fr       */
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
	char 		**map; // does we need that?
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
	int			Floor[3];
	int			Ceiling[3];
} t_map;

typedef struct s_game
{
	t_map	*game;
} t_game;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_player	player;
	t_map		map;
	t_game		game;
} t_vars;

int		parsing(int argc, char **argv);
void	ft_error(char *str);
void    init_vars(t_vars *vars);
int		game(t_vars *vars);
void	simple_parser(t_map *map, char *path);
void	free_mlx(t_vars *vars);
void	gameplay(t_vars *vars);
void	free_and_exit(t_vars *vars);
int		escape(int keycode, t_vars *vars);
int		x_button(t_vars *vars);


#endif