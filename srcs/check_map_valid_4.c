/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:12:36 by hson              #+#    #+#             */
/*   Updated: 2021/01/11 19:17:04 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		chk_map_top(t_game *game)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(game->map[0]))
	{
		if (!(game->map[0][i] == '1' || game->map[0][i] == ' '))
			return (ft_map_error(game));
		i++;
	}
	return (1);
}

int		chk_map_left(t_game *game, int i, int j)
{
	while (game->map[i][j] == ' ')
		j++;
	if (game->map[i][j] != '1')
		return (ft_map_error(game));
	return (1);
}

int		chk_map_right(t_game *game, int i, int j)
{
	while (game->map[i][j] == ' ')
		j--;
	if (game->map[i][j] != '1')
		return (ft_map_error(game));
	return (1);
}

int		chk_map_bottom(t_game *game, int i)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(game->map[i]))
	{
		if (!(game->map[i][j] == '1' || game->map[i][j] == ' '))
			return (ft_map_error(game));
		j++;
	}
	return (1);
}

int		chk_map_valid(t_game *game)
{
	int	i;

	if (!chk_map_top(game))
		return (ft_map_error(game));
	i = 0;
	while (i < game->map_h)
	{
		if (!chk_map_left(game, i, 0))
			return (ft_map_error(game));
		if (!chk_map_right(game, i, ft_strlen(game->map[i]) - 1))
			return (ft_map_error(game));
		i++;
	}
	if (!chk_map_bottom(game, i - 1))
		return (ft_map_error(game));
	return (1);
}
