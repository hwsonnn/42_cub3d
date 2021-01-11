/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_floor_ceiling_6.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:12:53 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:19:19 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_floor_ceiling_color(t_game *game)
{
	int x;
	int y;

	y = game->height / 2;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			game->buf[y][x] = game->floor_color;
			game->buf[game->height - y - 1][x] = game->ceiling_color;
			x++;
		}
		y++;
	}
}
