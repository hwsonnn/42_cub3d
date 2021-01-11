/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:12:49 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:20:07 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			game->img.addr[y * game->width + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	raycasting(t_game *game)
{
	int	x;

	cast_floor_ceiling_color(game);
	x = 0;
	while (x < game->width)
	{
		init_ray(game, &game->ray, &game->player, x);
		calc_side_dist(&game->ray, &game->player);
		apply_dda(game, &game->ray);
		calc_line_h(game, &game->ray);
		get_wall_texture(game, &game->ray, x);
		game->z_buf[x] = game->ray.calc_wall_dist;
		x++;
	}
}

void	sprite_casting(t_game *game)
{
	int	i;

	sort_sprite(game, &game->player);
	i = 0;
	while (i < game->num_sprite)
	{
		set_sprite(game, &game->player, &game->sp_ray, i);
		get_sp_height(game, &game->sp_ray);
		get_sp_width(game, &game->sp_ray);
		get_sp_texture(game, &game->sp_ray);
		i++;
	}
}

int		main_loop(t_game *game)
{
	raycasting(game);
	sprite_casting(game);
	draw(game);
	key_update(game);
	return (0);
}
