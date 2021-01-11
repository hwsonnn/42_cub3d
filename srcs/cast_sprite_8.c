/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprite_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:17:53 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:19:22 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_sprite(t_game *game, t_player *player, t_sprite_ray *sp_ray, int i)
{
	sp_ray->x = game->sprite[i].x - player->x;
	sp_ray->y = game->sprite[i].y - player->y;
	sp_ray->inverse_det = 1.0\
		/ (player->plane_x * player->dir_y - player->dir_x * player->plane_y);
	sp_ray->transform_x = sp_ray->inverse_det\
				* (player->dir_y * sp_ray->x - player->dir_x * sp_ray->y);
	sp_ray->transform_y = sp_ray->inverse_det\
				* (-player->plane_y * sp_ray->x + player->plane_x * sp_ray->y);
	sp_ray->sp_screen_x = (int)((game->width / 2)\
				* (1 + sp_ray->transform_x / sp_ray->transform_y));
}

void	get_sp_height(t_game *game, t_sprite_ray *sp_ray)
{
	sp_ray->sp_heignt = (int)fabs(game->height / sp_ray->transform_y);
	sp_ray->draw_start_y = game->height / 2 - sp_ray->sp_heignt / 2;
	if (sp_ray->draw_start_y < 0)
		sp_ray->draw_start_y = 0;
	sp_ray->draw_end_y = game->height / 2 + sp_ray->sp_heignt / 2;
	if (sp_ray->draw_end_y >= game->height)
		sp_ray->draw_end_y = game->height - 1;
}

void	get_sp_width(t_game *game, t_sprite_ray *sp_ray)
{
	sp_ray->sp_width = (int)fabs(game->height / sp_ray->transform_y);
	sp_ray->draw_start_x = sp_ray->sp_screen_x - sp_ray->sp_width / 2;
	if (sp_ray->draw_start_x < 0)
		sp_ray->draw_start_x = 0;
	sp_ray->draw_end_x = sp_ray->sp_screen_x + sp_ray->sp_width / 2;
	if (sp_ray->draw_end_x >= game->width)
		sp_ray->draw_end_x = game->width - 1;
}

void	get_sp_texture(t_game *game, t_sprite_ray *sp_ray)
{
	int	x;
	int	y;

	x = sp_ray->draw_start_x;
	while (x < sp_ray->draw_end_x)
	{
		sp_ray->tex_x = (int)((x - sp_ray->sp_screen_x + sp_ray->sp_width / 2)\
								* TEX_W / sp_ray->sp_width);
		if (sp_ray->transform_y > 0 && sp_ray->transform_y < game->z_buf[x]\
					&& x > 0 && x < game->width)
		{
			y = sp_ray->draw_start_y;
			while (y < sp_ray->draw_end_y)
			{
				sp_ray->tex_y = (int)((y - game->height / 2\
						+ sp_ray->sp_heignt / 2) * TEX_H / sp_ray->sp_heignt);
				sp_ray->color = game->texture[4][TEX_W * sp_ray->tex_y\
														+ sp_ray->tex_x];
				if ((sp_ray->color & 0xFFFFFF) != 0)
					game->buf[y][x] = sp_ray->color;
				y++;
			}
		}
		x++;
	}
}
