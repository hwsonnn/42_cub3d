/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_wall_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:12:59 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:19:25 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray(t_game *game, t_ray *ray, t_player *player, int x)
{
	ray->cam_x = (2 * x / (double)game->width) - 1;
	ray->raydir_x = player->dir_x + player->plane_x * ray->cam_x;
	ray->raydir_y = player->dir_y + player->plane_y * ray->cam_x;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->delta_dist_x = fabs(1 / ray->raydir_x);
	ray->delta_dist_y = fabs(1 / ray->raydir_y);
	ray->hit = 0;
}

void	calc_side_dist(t_ray *ray, t_player *player)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

void	apply_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = (ray->step_x == -1) ? 0 : 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = (ray->step_y == -1) ? 2 : 3;
		}
		if (game->map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

void	calc_line_h(t_game *game, t_ray *ray)
{
	if (ray->side <= 1)
		ray->calc_wall_dist = (ray->map_x - game->player.x\
				+ (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->calc_wall_dist = (ray->map_y - game->player.y\
				+ (1 - ray->step_y) / 2) / ray->raydir_y;
	ray->line_h = (int)(game->height / ray->calc_wall_dist);
	ray->draw_start = game->height / 2 - ray->line_h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = game->height / 2 + ray->line_h / 2;
	if (ray->draw_end >= game->height)
		ray->draw_end = game->height - 1;
}

void	get_wall_texture(t_game *game, t_ray *ray, int x)
{
	int	y;

	if (ray->side <= 1)
		ray->wall_x = game->player.y + ray->calc_wall_dist * ray->raydir_y;
	else
		ray->wall_x = game->player.x + ray->calc_wall_dist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_W);
	if (ray->side == 1 || ray->side == 2)
		ray->tex_x = TEX_W - ray->tex_x - 1;
	ray->step = (1.0 / ray->line_h) * TEX_H;
	ray->tex_pos = (ray->draw_start - (game->height / 2 - ray->line_h / 2))\
						* ray->step;
	y = ray->draw_start - 1;
	while (++y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_H - 1);
		ray->tex_pos += ray->step;
		ray->color = game->texture[ray->side][TEX_H * ray->tex_y + ray->tex_x];
		if (ray->side == 2 || ray->side == 3)
			ray->color = (ray->color >> 1) & 8355711;
		game->buf[y][x] = ray->color;
	}
}
