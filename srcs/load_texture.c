/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:13:41 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:20:04 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	chk_texture_file(t_game *game)
{
	int n;
	int s;
	int w;
	int e;
	int sp;

	if ((n = open(game->n_tex_path, O_RDONLY)) == -1)
		ft_tex_error(game);
	if ((s = open(game->s_tex_path, O_RDONLY)) == -1)
		ft_tex_error(game);
	if ((w = open(game->w_tex_path, O_RDONLY)) == -1)
		ft_tex_error(game);
	if ((e = open(game->e_tex_path, O_RDONLY)) == -1)
		ft_tex_error(game);
	if ((sp = open(game->sp_tex_path, O_RDONLY)) == -1)
		ft_tex_error(game);
	close(n);
	close(s);
	close(w);
	close(e);
	close(sp);
}

void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->img_w, &img->img_h);
	img->addr = (int *)mlx_get_data_addr(img->img,\
					&img->bpp, &img->size_l, &img->endian);
	y = 0;
	while (y < img->img_h)
	{
		x = 0;
		while (x < img->img_w)
		{
			texture[y * img->img_w + x] = img->addr[y * img->img_w + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img->img);
}

void	load_texture(t_game *game)
{
	t_img	img;

	chk_texture_file(game);
	load_image(game, game->texture[0], game->n_tex_path, &img);
	load_image(game, game->texture[1], game->s_tex_path, &img);
	load_image(game, game->texture[2], game->w_tex_path, &img);
	load_image(game, game->texture[3], game->e_tex_path, &img);
	load_image(game, game->texture[4], game->sp_tex_path, &img);
	free(game->n_tex_path);
	free(game->s_tex_path);
	free(game->w_tex_path);
	free(game->e_tex_path);
	free(game->sp_tex_path);
}
