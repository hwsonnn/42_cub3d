/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player_10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:13:08 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:19:30 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player(t_game *game, t_player *player, double move_speed)
{
	if (game->map[(int)(player->x + player->dir_x * move_speed)]\
				[(int)player->y] != '1')
		player->x += player->dir_x * move_speed;
	if (game->map[(int)player->x]\
			[(int)(player->y + player->dir_y * move_speed)] != '1')
		player->y += player->dir_y * move_speed;
}

void	move_player_l_r(t_game *game, t_player *player, double move_speed)
{
	double l_dir_x;
	double l_dir_y;

	l_dir_x = player->dir_x * cos(PI / 2) - player->dir_y * sin(PI / 2);
	l_dir_y = player->dir_x * sin(PI / 2) + player->dir_y * cos(PI / 2);
	if (game->map[(int)(player->x + l_dir_x * move_speed)][(int)player->y]\
					!= '1')
		player->x += l_dir_x * move_speed;
	if (game->map[(int)player->x][(int)(player->y + l_dir_y * move_speed)]\
					!= '1')
		player->y += l_dir_y * move_speed;
}

void	rotate_player(t_player *player, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed)\
						- player->dir_y * sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed)\
						- player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed)\
						+ player->plane_y * cos(rot_speed);
}
