/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:13:35 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:19:59 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(t_player *player)
{
	player->x = 13;
	player->y = 15;
	player->dir_x = -1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.66;
	player->move_speed = 0.05;
	player->rot_speed = 0.05;
}

void	init_key(t_key *key)
{
	key->key_w = 0;
	key->key_a = 0;
	key->key_s = 0;
	key->key_d = 0;
	key->key_left = 0;
	key->key_right = 0;
	key->key_esc = 0;
}

void	init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->map_w = 0;
	game->map_h = 0;
	game->buf = NULL;
	game->z_buf = NULL;
	game->texture = NULL;
	game->map = NULL;
	game->n_tex_path = NULL;
	game->s_tex_path = NULL;
	game->w_tex_path = NULL;
	game->e_tex_path = NULL;
	game->sp_tex_path = NULL;
	game->floor_color = 0;
	game->ceiling_color = 0;
	game->num_sprite = 0;
}

void	init_img(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, game->width, game->height);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img,\
						&game->img.bpp, &game->img.size_l, &game->img.endian);
}
