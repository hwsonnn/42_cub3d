/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:21:33 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:20:25 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sort_sp_sub(t_game *game)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = 0;
	while (i < game->num_sprite)
	{
		j = 0;
		while (j < game->num_sprite - 1)
		{
			if (game->sprite[j].dist < game->sprite[j + 1].dist)
			{
				tmp = game->sprite[j];
				game->sprite[j] = game->sprite[j + 1];
				game->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprite(t_game *game, t_player *player)
{
	int	i;

	i = 0;
	while (i < game->num_sprite)
	{
		game->sprite[i].dist =\
		((player->x - game->sprite[i].x) * (player->x - game->sprite[i].x)\
		+ (player->y - game->sprite[i].y) * (player->y - game->sprite[i].y));
		i++;
	}
	sort_sp_sub(game);
}
