/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:32:32 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/27 02:57:35 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "libft/libft.h"
# include "libft/printf/ft_printf.h"
# include "libft/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_check
{
	int			r;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			s;
	int			f;
	int			c;
	int			map;
	int			player;
}				t_check;

typedef struct	s_file
{
	int			res_x;
	int			res_y;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			floor_rgb;
	int			ceil_rgb;
	char		*map_lines;
	int			map_length;
	char		**map;
	char		player;
}				t_file;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		turn_speed;
}				t_player;

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct	s_dda
{
	int			x;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		walldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_dda;

typedef struct	s_spr
{
	int			num;
	double		*z_buffer;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_y;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_end_x;
	int			stripe;
	int			tex_x;
	int			tex_y;
	int			d;
	int			color;
}				t_spr;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
}				t_sprite;

typedef struct	s_all
{
	t_check		*check;
	t_file		*file;
	t_mlx		*mlx;
	t_player	*player;
	t_image		**image;
	t_dda		*dda;
	t_spr		*spr;
	t_sprite	**sprite;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_left;
	int			key_right;
}				t_all;

/*
**main.c
*/
void			preprocessing_parameters(char *file_path, t_all *all);
/*
**file_parameters.c
*/
void			imbibe_file_parameters(int fd, t_all *all);
/*
**little_utils.c
*/
void			ft_error(char *text);
void			skip_spaces(char *line, int *i);
void			fill_texture(char **check, int *c, char *line, int i);
void			check_color_file(char *line, int *i);
int				create_trgb(int t, int r, int g, int b);
/*
**little_utils_2.c
*/
void			check_map_line(t_all *all, char *line);
int				check_empty_map_line(int fd, char *line);
char			*get_space_line(int map, int len);
void			check_player(t_all *all);
void			check_surroundings(char **map, int y, int x);
/*
**little_utils_3.c
*/
void			validate_parameters(t_check *check);
int				ft_atoi_trick(char *line);
void			skip_digits_and_spaces(char *line, int *i);
/*
**little_utils_4.c
*/
void			check_c_f_on_trash(char *line, int i);
/*
**map_parsing.c
*/
void			fill_map(int fd, t_all *all, char *line);
/*
**player.c
*/
void			set_player_parameters(t_all *all);
/*
**sprite_init.c
*/
void			set_sprite_parameters(t_all *all);
/*
**run_engine.c
*/
void			run_engine(t_all *all);
/*
**engine_utils.c
*/
void			move_forward_backward(t_all *all);
void			move_left_right(t_all *all);
void			rotate_left_right(t_all *all, double old_dir_x,
											double old_plane_x);
void			what_side_got_hit(t_all *all);
void			calculate_texture_x(t_all *all);
/*
**render_frame.c
*/
void			render_frame(t_all *all);
/*
**draw.c
*/
void			draw_line(t_all *all);
/*
**sprite_render.c
*/
void			render_sprites(t_all *all);
/*
**sprite_utils.c
*/
void			sort_sprites(t_all *all);
void			sprite_distance(t_all *all);
void			calculate_sprite_height(t_all *all);
void			calculate_sprite_width(t_all *all);
/*
**pixel.c
*/
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
int				my_pixel_take(t_image *image, int x, int y);
/*
**create_bmp.c
*/
void			create_bmp(char *file, t_all *all);
#endif
