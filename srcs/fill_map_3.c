/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:52:11 by sonheewon         #+#    #+#             */
/*   Updated: 2021/01/11 16:14:18 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_dir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (-1);
}

int		is_map_val(char c)
{
	if (is_dir(c) == 1 || (c >= '0' && c <= '2')
			|| c == ' ' || c == '\n')
		return (1);
	return (-1);
}

int		chk_player_dir(t_game *game, int i, int j, char dir)
{
	int		rot;

	if (is_dir(dir) == 1)
	{
		game->player.x = i;
		game->player.y = j;
		rot = 0;
		if (dir == 'N')
			rot = 0;
		else if (dir == 'W')
			rot = 90;
		else if (dir == 'S')
			rot = 180;
		else if (dir == 'E')
			rot = 270;
		rotate_player(&game->player, rot * PI / 180);
		return (1);
	}
	if (dir == '2')
		game->num_sprite++;
	return (0);
}

int		fill_map(t_game *game, t_list *lst)
{
	int		i;
	int		j;
	char	*map_line;
	int		player_dir;

	i = 0;
	player_dir = 0;
	while (i < game->map_h)
	{
		j = 0;
		map_line = (char *)lst->content;
		while (j < ft_strlen(map_line))
		{
			if (is_map_val(map_line[j]) == -1)
				return (ft_map_error(game));
			game->map[i][j] = map_line[j];
			player_dir += chk_player_dir(game, i, j, map_line[j]);
			j++;
		}
		lst = lst->next;
		i++;
	}
	if (player_dir != 1)
		return (ft_map_error(game));
	return (1);
}
