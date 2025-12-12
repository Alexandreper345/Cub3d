/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:57:40 by alda-sil          #+#    #+#             */
/*   Updated: 2025/12/11 20:47:09 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_ColorRGB
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_ColorRGB;

typedef struct s_fps
{
	struct timeval	timeOfDay;
	double			time;
	double			oldTime;
	double			frameTime;
	double			mv;
	double			rs;
}					t_fps;

typedef struct s_camera
{
	int				color;
	int				y;
	int				x;
	int				texX;
	int				texY;
	int				side;
	int				drawEnd;
	int				drawStart;
	int				lineHeight;
	int				hit;
	int				mapX;
	int				mapY;
	int				height;
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
	double			rayDirX;
	double			rayDirY;
}					t_camera;

typedef struct s_player
{
	int				stepY;
	int				stepX;
	double			posX;
	double			posY;
}					t_player;

typedef struct s_texture
{
	void			*img_ptr;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_len;
	int				endian;
}					t_texture;

typedef struct s_map
{
	char			**matriz;
	char			**map;
	char			**dup_map;
	char			*NO_path;
	char			*SO_path;
	char			*WE_path;
	char			*EA_path;
	t_texture		NO;
	t_texture		SO;
	t_texture		WE;
	t_texture		EA;
	int				tex_height;
	int				tex_width;
	int				height;
	int				width;
	int				x_ceil;
	int				x_floor;
	int				Floor_color;
	int				Ceiling_color;
}					t_map;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	t_player		*player;
	t_map			*map;
	t_camera		camera;
	t_texture		buffer;
	t_fps			fps;
}					t_vars;

void				ft_error(char *str);
void				my_pixel_put_to_buffer(t_texture *img, int x, int y,
						int color);
void				simple_parser(t_map *map, char *path);
void				free_mlx(t_vars *vars);
void				game_settings(t_vars *vars);
void				free_and_exit(t_vars *vars);
void				calc_fps(t_fps *fps);
void				dda(t_map *map, t_camera *cam, t_player *player,
						t_vars *vars);
void				free_matriz(char **matriz);
void				init_vars(t_vars *vars, char *map_path);
int					game(t_vars *vars);
int					escape(int keycode, t_vars *vars);
int					x_button(t_vars *vars);
int					gameplay(t_vars *vars);
int					get_position_map(char **matriz, t_map *map);
int					get_texture_pixel_color(t_texture *tex, int x, int y);
int					walk(int keycode, t_vars *vars);
int					get_position_player(char **map, t_vars *vars_main);
int					check_file_path(int argc, char **argv);
int					init_matriz(t_map *map, char *path);
int					parsing(t_map *map, t_vars *vars_main);
int					malloc_in_pointer_y(t_map *map, char *line, int fd,
						char *path);
int					get_height_map(char **matriz);
int					get_width_map(char **matriz);
int					init_process_flood(t_map *map);
int					ft_strcmp(const char *s1, const char *s2);
int					check_file_before_map(char *line);
int					check_map_valid(char **map);
int					check_file(char **map);
int					get_path_text(t_map *map);
int					check_duplacate_map(char **map);
void				init_buffer(t_vars *vars);
int					recreate_matriz(t_vars *vars, char *path);

// void    	init_vars(t_vars *vars);
t_texture			*determinate_texture(t_camera *cam, t_vars *vars,
						t_map *map);

#endif