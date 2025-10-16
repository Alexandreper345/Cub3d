/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:57:40 by alda-sil          #+#    #+#             */
/*   Updated: 2025/10/16 12:49:31 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

typedef struct s_ColorRGB {
    unsigned char r;  // Quantidade de Vermelho (de 0 a 255)
    unsigned char g;  // Quantidade de Verde (de 0 a 255)
    unsigned char b;  // Quantidade de Azul (de 0 a 255)
} ColorRGB;

typedef struct s_fps
{
	struct 	timeval	timeOfDay;
	double	time;
	double	oldTime;
	double	frameTime;
	double	moveSpeed;
	double	rotSpeed;
} t_fps;

typedef struct s_camera
{
	int				color;
	int				y;
	int				texX;
	int				texY;
	int				side;
	int				drawEnd;
	int				drawStart;
	int				lineHeight;
	int				hit;
	int				mapX;
	int				mapY;
	double			step;
	double			texPos;
	double			camX;
	double			wallX;
	double			perpWallDist;
	double			deltaDistX;
	double			deltaDistY;
	double			sideDistX;
	double			sideDistY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
    double         	rayDirX;
    double         	rayDirY;
	int				height;
} t_camera;

typedef struct s_player
{
	int				stepY;
	int				stepX;
	double				posX;
	double				posY;
	int				width;
	int				height;
} t_player;

typedef struct s_texture
{
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;


typedef	struct s_map
{
	char 		**map; // does we need that?
	char		*NO_path;
	char		*SO_path;
	char		*WE_path;
	char		*EA_path;
	t_texture	NO;
	t_texture	SO;
	t_texture	WE;
	t_texture	EA;
	int			tex_height;
	int			tex_width;
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
	t_camera	camera;
	t_texture	buffer;
	t_fps		fps;
} t_vars;

int			parsing(int argc, char **argv);
void		ft_error(char *str);
void    	init_vars(t_vars *vars);
int			game(t_vars *vars);
void		simple_parser(t_map *map, char *path);
void		free_mlx(t_vars *vars);
void		game_settings(t_vars *vars);
void		free_and_exit(t_vars *vars);
int			escape(int keycode, t_vars *vars);
int			x_button(t_vars *vars);
int			gameplay(t_vars *vars);
t_texture	*determinate_texture(t_camera *cam, t_vars *vars, t_map *map);
int			get_texture_pixel_color(t_texture *tex, int x, int y);
void		my_pixel_put_to_buffer(t_texture *img, int x, int y, int color);
void		calc_fps(t_fps *fps);




#endif