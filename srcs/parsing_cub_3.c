/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:12:08 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:20:21 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		parse_line(t_game *game, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0 && ft_strncmp(line, "R  ", 3) != 0)
		return (get_screen_size(game, line + 2));
	else if (ft_strncmp(line, "NO ", 3) == 0\
					&& ft_strncmp(line, "NO  ", 4) != 0)
		return (get_texture(game, line + 3, "NO"));
	else if (ft_strncmp(line, "SO ", 3) == 0\
					&& ft_strncmp(line, "SO  ", 4) != 0)
		return (get_texture(game, line + 3, "SO"));
	else if (ft_strncmp(line, "WE ", 3) == 0\
					&& ft_strncmp(line, "WE  ", 4) != 0)
		return (get_texture(game, line + 3, "WE"));
	else if (ft_strncmp(line, "EA ", 3) == 0\
					&& ft_strncmp(line, "EA  ", 4) != 0)
		return (get_texture(game, line + 3, "EA"));
	else if (ft_strncmp(line, "S ", 2) == 0 && ft_strncmp(line, "S  ", 3) != 0)
		return (get_texture(game, line + 2, "S"));
	else if (ft_strncmp(line, "F ", 2) == 0 && ft_strncmp(line, "F  ", 3) != 0)
		return (get_color(game, line + 2, 'F'));
	else if (ft_strncmp(line, "C ", 2) == 0 && ft_strncmp(line, "C  ", 3) != 0)
		return (get_color(game, line + 2, 'C'));
	else if (line[0] == '\0')
		return (1);
	return (0);
}

int		parse_map(t_game *game, char *first_line)
{
	t_list	*lst;
	char	*line;

	lst = ft_lstnew(ft_strdup(first_line));
	free(first_line);
	while (get_next_line(game->fd, &line) > 0)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
	free(line);
	if (!get_map(game, lst))
		return (ft_map_error(game));
	return (1);
}

int		chk_cub_init(t_game *game)
{
	if (!game->width || !game->height
		|| !game->n_tex_path || !game->s_tex_path
		|| !game->e_tex_path || !game->w_tex_path
		|| !game->sp_tex_path
		|| !game->ceiling_color || !game->floor_color
		|| !game->map_h || !game->map_w || !game->map)
		return (ft_cub_error(game));
	return (1);
}

int		parse_cub(t_game *game, char *cub_file)
{
	char	*line;

	init_game(game);
	game->fd = open(cub_file, O_RDONLY);
	while (get_next_line(game->fd, &line) > 0)
	{
		if (parse_line(game, line) == -1)
			return (ft_cub_error(game));
		if (parse_line(game, line) == 0)
			break ;
		free(line);
	}
	if (!parse_map(game, line))
		return (ft_map_error(game));
	if (!chk_cub_init(game))
		return (ft_cub_error(game));
	if (!init_sprite(game))
		return (ft_error(game));
	return (1);
}
