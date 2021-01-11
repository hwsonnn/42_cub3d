/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:41:37 by sonheewon         #+#    #+#             */
/*   Updated: 2021/01/09 19:53:12 by hson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_bmp_h	get_bmph(int width, int height)
{
	t_bmp_h bmph;

	bmph.file_h.magic1 = 'B';
	bmph.file_h.magic2 = 'M';
	bmph.file_h.size = 54 + 4 * width * height;
	bmph.file_h.reserved1 = 0;
	bmph.file_h.reserved2 = 0;
	bmph.file_h.offset = 54;
	bmph.info_h.size = 40;
	bmph.info_h.width = width;
	bmph.info_h.height = -height;
	bmph.info_h.plane = 1;
	bmph.info_h.bit_per_pixel = 32;
	bmph.info_h.compression = 0;
	bmph.info_h.size_image = 4 * width * height;
	bmph.info_h.resolution_x = width;
	bmph.info_h.resolution_y = height;
	bmph.info_h.color_used = 0xffffff;
	bmph.info_h.color_important = 0;
	return (bmph);
}

void	get_img(t_game *game)
{
	int x;
	int y;

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
}

void	write_bmp(t_game *game, int fd)
{
	int	i;

	get_img(game);
	i = 0;
	while (i < (game->img.size_l / 4) * game->height)
	{
		if (i % (game->img.size_l / 4) < game->width)
			write(fd, &game->img.addr[i], 4);
		i++;
	}
}

int		save_bmp(t_game *game, int width, int height)
{
	t_bmp_h	bmph;
	char	*file_name;
	char	*file_path;
	int		fd;

	ft_printf("Type file name to be saved (MUST end with '.bmp')\n");
	get_next_line(0, &file_name);
	file_path = ft_strjoin("./bmp/", file_name);
	if ((fd = open(file_path, O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
		return (-1);
	bmph = get_bmph(width, height);
	write(fd, &bmph, 54);
	write_bmp(game, fd);
	ft_printf("[%s] file has been saved\n", file_name);
	free(file_name);
	free(file_path);
	close(fd);
	return (1);
}
