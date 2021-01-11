/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_or_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:13:21 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:19:47 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_error(t_game *game)
{
	ft_putstr("Error\n");
	if (game->fd)
		close(game->fd);
	exit(0);
	return (-1);
}

int	ft_arg_error(void)
{
	ft_putstr("argument Error\n");
	exit(0);
	return (-1);
}

int	ft_malloc_error(t_game *game)
{
	ft_putstr("malloc Error\n");
	if (game->fd)
		close(game->fd);
	exit(0);
	return (-1);
}

int	ft_cub_error(t_game *game)
{
	ft_putstr("cub Error\n");
	if (game->fd)
		close(game->fd);
	exit(0);
	return (-1);
}

int	ft_map_error(t_game *game)
{
	ft_putstr("map Error\n");
	if (game->fd)
		close(game->fd);
	exit(0);
	return (-1);
}
