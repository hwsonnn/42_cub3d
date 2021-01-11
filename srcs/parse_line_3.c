/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:54:31 by sonheewon         #+#    #+#             */
/*   Updated: 2021/01/09 19:20:13 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_screen_size(t_game *game, char *line)
{
	char **size;

	if (!(size = ft_split(line, ' ')))
		return (ft_cub_error(game));
	if (!size || !size[0] || !size[1])
		return (ft_cub_error(game));
	game->width = ft_atoi(size[0]);
	game->height = ft_atoi(size[1]);
	if (game->width > 1920)
		game->width = 1920;
	if (game->height > 1080)
		game->height = 1080;
	ft_free_2p(size);
	return (1);
}

int		get_texture(t_game *game, char *line, char *id)
{
	if (id[0] == 'N' && id[1] == 'O')
		game->n_tex_path = ft_strdup(line);
	else if (id[0] == 'S' && id[1] == 'O')
		game->s_tex_path = ft_strdup(line);
	else if (id[0] == 'W' && id[1] == 'E')
		game->w_tex_path = ft_strdup(line);
	else if (id[0] == 'E' && id[1] == 'A')
		game->e_tex_path = ft_strdup(line);
	else if (id[0] == 'S' && id[1] == '\0')
		game->sp_tex_path = ft_strdup(line);
	else
		return (ft_cub_error(game));
	return (1);
}

int		get_color(t_game *game, char *line, int id)
{
	char	**rgb;
	int		color;
	int		i;

	if (!(rgb = ft_split(line, ',')))
		return (ft_cub_error(game));
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (ft_cub_error(game));
	color = 0;
	i = 0;
	while (i < 3)
	{
		color *= 256;
		color += ft_atoi(rgb[i]);
		i++;
	}
	ft_free_2p(rgb);
	if (id == 'F')
		game->floor_color = color;
	else if (id == 'C')
		game->ceiling_color = color;
	return (1);
}
