/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_or_error_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:48:54 by sonheewon         #+#    #+#             */
/*   Updated: 2021/01/09 19:19:44 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_buf_error(t_game *game)
{
	ft_putstr("buf malloc Error\n");
	if (game->fd)
		close(game->fd);
	exit(0);
	return (-1);
}

int		ft_tex_error(t_game *game)
{
	ft_putstr("tex malloc Error\n");
	if (game->fd)
		close(game->fd);
	exit(0);
	return (-1);
}

void	ft_free_2p(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}
