/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 05:07:39 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/26 21:40:02 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
# include "vector/vector.h"
# include "parser/parser.h"
# include "gnl/get_next_line.h"

# define RESOL_WIDTH_MAX 1000000
# define RESOL_HEIGTH_MAX 500000

# define ERROR -1
# define WRONG_RESOL -1
# define WRONG_TEXTURE -2
# define WRONG_COLOR -3
# define KEY_DUPLICATE -4
# define KEY_LOW -5
# define NOT_XPM -6
# define WRONG_PATH -7
# define WRONG_COLOR_COUNT -8
# define WRONG_MAP_OTHER_SYM -9
# define WRONG_MAP -10
# define MAP_NOT_CLOSED -11
# define NOT_MALLOC -15
# define EMPTY_SPACE 0
# define WALL 1
# define ITEM 2

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SCALE 64
# define SPEED 1

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_wall_cast
{
	t_vec_int	cord;
	t_vec_d		ray_dir;
	t_vec_d		side_dist;
	t_vec_d		delta_dist;
	t_vec_int	map;
	t_vec_int	step;
	double		perp_wall_dist;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			text_num;
	double		wall_x;
	int			tex_x;
	double		step_d;
	double		text_pos;
}t_wall_cast;

typedef struct s_sprite_cast
{
	t_vec_d	transform;
	t_vec_d	sprite;
	double	invDet;
	int		sprite_screen_x;
	int		spriteHeight;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		tex_x;
	int		d;
	int		tex_y;
	int		color;
}t_sprite_cast;

typedef struct s_sprite
{
	t_vec_d		*pos;
	int			count;
}t_sprite;

typedef struct s_key
{
	int				key_a;
	int				key_w;
	int				key_s;
	int				key_d;
	int				key_left;
	int				key_right;
	int				key_esc;
}t_key;

typedef struct s_info
{
	int				flag_save;
	t_resolution	resol;
	t_path			path;
	t_color			f_color;
	t_color			c_color;
	t_map			map;
	t_vec_d			pos;
	t_vec_d			dir;
	t_vec_d			plane;
	void			*mlx;
	void			*win;
	t_key			key;
	t_img			img;
	double			move_speed;
	double			rot_speed;
	int				**texture;
	int				**buf;
	double			*len_buf;
	t_sprite		sprite;
	char			*file;
}t_info;

void		ft_wich_error(int error);
void		check_press(int key, t_info *info);
void		check_release(int key, t_info *info);

int			ft_mass_strlen(char **mass);

void		load_texture(t_info *info);
int			set_texture(t_info *info);
void		is_save(char **argv, t_info *info, int argc);
void		floor_cast(t_info *info);
void		wall_cast(t_info *info);
void		info_init(t_info *info); // обнуление инфо
void		buf_init(t_info *info);
void		key_update(t_info *info);
// Pars
void		parser_map_write(t_info *info, int fd, char *line);
void		parser_color(char *line, t_info *info);
void		map_check(t_info *info);
int			parser(t_info *info);
int			is_info_full(t_info	info);
int			tempo_parser(char *line, t_info *info, int fd);
void		set_dir_plane(t_info *info, char symbol);
void		is_cub(char *line);
void		set_cub(t_info *info, char **argv, int argc);

t_vec_d		*sprite_push(t_sprite *sprite, int x, int y);

void		wall_wich_dir(t_wall_cast *wall, t_info *info);
void		wall_init(t_wall_cast *wall, t_info *info);
void		load_image(t_info *info, int *texture, char *path, t_img *img);
// Key
int			key_release(int key, t_info *info);
int			key_press(int key, t_info *info);
void		key_update_right(t_info *info);
void		key_update_left(t_info *info);

double		sprite_distance(t_info *info, int wich);
t_vec_d		*sprite_push(t_sprite *sprite, int x, int y);
void		sort_sprite(t_info *info);
void		sprite_cast(t_info *info);
void		create_screenshot(t_info *info);
#endif
