/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:53:17 by sonheewon         #+#    #+#             */
/*   Updated: 2021/01/11 19:17:53 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		max_cont_size(t_list *lst)
{
	int	max;

	max = 0;
	while (lst)
	{
		if ((int)ft_strlen((char *)lst->content) > max)
			max = ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	return (max);
}

int		make_map_init(t_game *game, t_list *lst)
{
	int	i;
	int	j;

	game->map_h = ft_lstsize(lst);
	if (!(game->map = (char **)malloc(sizeof(char *) * game->map_h)))
		return (ft_malloc_error(game));
	game->map_w = max_cont_size(lst);
	i = 0;
	while (i < game->map_h)
	{
		if (!(game->map[i] = (char *)malloc(sizeof(char) * (game->map_w + 1))))
			return (ft_malloc_error(game));
		j = -1;
		while (j++ < (int)ft_strlen(lst->content) - 1)
			game->map[i][j] = 0;
		while (j++ < game->map_w - 1)
			game->map[i][j] = ' ';
		game->map[i][game->map_w] = '\0';
		i++;
		lst = lst->next;
	}
	return (1);
}

int		get_map(t_game *game, t_list *lst)
{
	if (!make_map_init(game, lst))
		return (ft_map_error(game));
	if (!fill_map(game, lst))
		return (ft_map_error(game));
	ft_lstclear(&lst, free);
	if (!chk_map_valid(game))
		return (ft_map_error(game));
	return (1);
}
