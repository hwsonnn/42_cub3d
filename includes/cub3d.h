/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:14:11 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 21:23:18 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include "get_next_line.h"
# include "key_macos.h"
# include "bitmap.h"

# define TEX_W 	64
# define TEX_H 	64

# define PI		3.14159265359

typedef struct		s_img
{
	void			*img;
	int				*addr;
	int				bpp;
	int				size_l;
	int				endian;
	int				img_w;
	int				img_h;
}					t_img;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			dist;
}					t_sprite;

typedef struct		s_player
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
}					t_player;

typedef struct		s_ray
{
	double			cam_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			calc_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_h;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_x;
	int				tex_y;
	int				color;
}					t_ray;

typedef struct		s_sprite_ray
{
	double			x;
	double			y;
	double			inverse_det;
	double			transform_x;
	double			transform_y;
	int				sp_screen_x;
	int				sp_heignt;
	int				draw_start_y;
	int				draw_end_y;
	int				sp_width;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
	int				color;
}					t_sprite_ray;

typedef struct		s_key
{
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_left;
	int				key_right;
	int				key_esc;
}					t_key;

typedef struct		s_game
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_key			key;
	t_player		player;
	t_ray			ray;
	t_sprite_ray	sp_ray;
	t_sprite		*sprite;
	int				**buf;
	double			*z_buf;
	int				**texture;
	int				fd;
	int				width;
	int				height;
	int				map_w;
	int				map_h;
	char			**map;
	char			*n_tex_path;
	char			*s_tex_path;
	char			*w_tex_path;
	char			*e_tex_path;
	char			*sp_tex_path;
	int				floor_color;
	int				ceiling_color;
	int				num_sprite;
}					t_game;

/*
** main_loop
*/
void				draw(t_game *game);
void				raycasting(t_game *game);
void				sprite_casting(t_game *game);
int					main_loop(t_game *game);

/*
** raycasting.c
*/
void				cast_floor_ceiling_color(t_game *game);
void				init_ray(t_game *game, t_ray *ray, t_player *player, int x);
void				calc_side_dist(t_ray *ray, t_player *player);
void				apply_dda(t_game *game, t_ray *ray);
void				calc_line_h(t_game *game, t_ray *ray);
void				get_wall_texture(t_game *game, t_ray *ray, int x);

/*
** sprite_casting
*/
void				sort_sp_sub(t_game *game);
void				sort_sprite(t_game *game, t_player *player);
void				set_sprite(t_game *game, t_player *player,\
								t_sprite_ray *sp_ray, int i);
void				get_sp_height(t_game *game, t_sprite_ray *sp_ray);
void				get_sp_width(t_game *game, t_sprite_ray *sp_ray);
void				get_sp_texture(t_game *game, t_sprite_ray *sp_ray);

/*
** deal_key.c
*/
void				key_update(t_game *game);
int					key_press(int key, t_game *game);
int					key_release(int key, t_game *game);
int					ft_exit(int zero);

/*
** control_player.c
*/
void				move_player(t_game *game,\
							t_player *player, double move_speed);
void				move_player_l_r(t_game *game,\
							t_player *plyaer, double move_speed);
void				rotate_player(t_player *player, double rot_speed);

/*
** init.c
*/
void				init_player(t_player *player);
void				init_key(t_key *key);
void				init_game(t_game *game);
int					init_buf(t_game *game);
int					init_z_buf(t_game *game);
int					init_tex(t_game *game);
void				init_img(t_game *game);
int					init_sprite(t_game *game);

/*
** free_or_error.c
*/
int					ft_error(t_game *game);
int					ft_arg_error(void);
int					ft_malloc_error(t_game *game);
int					ft_cub_error(t_game *game);
int					ft_map_error(t_game *game);
int					ft_buf_error(t_game *game);
int					ft_tex_error(t_game *game);
void				ft_free_2p(char **res);

/*
** load_texture.c
*/
void				chk_texture_file(t_game *game);
void				load_image(t_game *game, int *texture,\
							char *path, t_img *img);
void				load_texture(t_game *game);

/*
** parsing_cub.c
*/
int					chk_map_valid(t_game *game);
int					is_dir(char c);
int					is_map_val(char c);
int					chk_player_dir(t_game *game, int i, int j, char dir);
int					fill_map(t_game *game, t_list *lst);

int					max_cont_size(t_list *lst);
int					make_map_init(t_game *game, t_list *lst);
int					get_map(t_game *game, t_list *lst);
int					parse_map(t_game *game, char *first_line);

int					get_screen_size(t_game *game, char *line);
int					get_texture(t_game *game, char *line, char *id);
int					get_color(t_game *game, char *line, int id);
int					parse_line(t_game *game, char *line);

int					chk_cub_init(t_game *game);
int					parse_cub(t_game *game, char *cub_file);

/*
** check_map_valid.c
*/
int					chk_map_top(t_game *game);
int					chk_map_left(t_game *game, int i, int j);
int					chk_map_right(t_game *game, int i, int j);
int					chk_map_bottom(t_game *game, int i);

/*
** bitmap.c
*/
t_bmp_h				get_bmph(int width, int height);
void				get_img(t_game *game);
void				write_bmp(t_game *game, int fd);
int					save_bmp(t_game *game, int width, int height);

#endif
