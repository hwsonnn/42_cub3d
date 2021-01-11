/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:13:04 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:19:37 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_update(t_game *game)
{
	if (game->key.key_w)
		move_player(game, &game->player, game->player.move_speed);
	if (game->key.key_s)
		move_player(game, &game->player, -game->player.move_speed);
	if (game->key.key_a)
		move_player_l_r(game, &game->player, game->player.move_speed);
	if (game->key.key_d)
		move_player_l_r(game, &game->player, -game->player.move_speed);
	if (game->key.key_left)
		rotate_player(&game->player, game->player.rot_speed);
	if (game->key.key_right)
		rotate_player(&game->player, -game->player.rot_speed);
	if (game->key.key_esc)
		exit(0);
}

int		key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W || key == KEY_UP)
		game->key.key_w = 1;
	else if (key == KEY_S || key == KEY_DOWN)
		game->key.key_s = 1;
	else if (key == KEY_A)
		game->key.key_a = 1;
	else if (key == KEY_D)
		game->key.key_d = 1;
	else if (key == KEY_LEFT)
		game->key.key_left = 1;
	else if (key == KEY_RIGHT)
		game->key.key_right = 1;
	return (0);
}

int		key_release(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W || key == KEY_UP)
		game->key.key_w = 0;
	else if (key == KEY_S || key == KEY_DOWN)
		game->key.key_s = 0;
	else if (key == KEY_A)
		game->key.key_a = 0;
	else if (key == KEY_D)
		game->key.key_d = 0;
	else if (key == KEY_LEFT)
		game->key.key_left = 0;
	else if (key == KEY_RIGHT)
		game->key.key_right = 0;
	return (0);
}

int		ft_exit(int zero)
{
	exit(zero);
	return (zero);
}
