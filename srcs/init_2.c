/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:20:32 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:19:56 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		init_buf(t_game *game)
{
	int i;
	int j;

	if (!(game->buf = (int **)malloc(sizeof(int *) * game->height)))
		return (-1);
	i = 0;
	while (i < game->height)
	{
		if (!(game->buf[i] = (int *)malloc(sizeof(int) * game->width)))
			return (-1);
		j = 0;
		while (j < game->width)
		{
			game->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		init_z_buf(t_game *game)
{
	int	i;

	if (!(game->z_buf = (double *)malloc(sizeof(double) * game->width)))
		return (-1);
	i = 0;
	while (i < game->width)
	{
		game->z_buf[i] = 0;
		i++;
	}
	return (1);
}

int		init_tex(t_game *game)
{
	int i;
	int j;

	if (!(game->texture = (int **)malloc(sizeof(int *) * 5)))
		return (-1);
	i = 0;
	while (i < 5)
	{
		if (!(game->texture[i] = (int *)malloc(sizeof(int) * (TEX_H * TEX_W))))
			return (-1);
		j = 0;
		while (j < TEX_H * TEX_W)
		{
			game->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		init_sprite(t_game *game)
{
	int x;
	int y;
	int i;

	if (!(game->sprite =\
			(t_sprite *)malloc(sizeof(t_sprite) * game->num_sprite)))
		return (ft_malloc_error(game));
	x = 0;
	i = 0;
	while (x < game->map_h)
	{
		y = 0;
		while (y < game->map_w)
		{
			if (game->map[x][y] == '2')
			{
				game->sprite[i].x = x + 0.5f;
				game->sprite[i].y = y + 0.5f;
				i++;
			}
			y++;
		}
		x++;
	}
	return (1);
}
