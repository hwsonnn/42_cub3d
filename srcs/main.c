/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonheewon <sonheewon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:13:48 by hson              #+#    #+#             */
/*   Updated: 2021/01/09 19:20:10 by sonheewon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_init_buffer(t_game *game)
{
	if (init_buf(game) == -1)
		return (ft_buf_error(game));
	if (init_z_buf(game) == -1)
		return (ft_buf_error(game));
	if (init_tex(game) == -1)
		return (ft_tex_error(game));
	return (0);
}

void	play_game(t_game game)
{
	game.win = mlx_new_window(game.mlx, game.width, game.height, "cub3d");
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &ft_exit, 0);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}

int		main(int ac, char **av)
{
	t_game game;

	game.mlx = mlx_init();
	if (ac == 1 || ac > 3 ||
		(ac == 3 && ft_strcmp("--save", av[2]) != 0))
		return (ft_arg_error());
	init_player(&game.player);
	init_key(&game.key);
	if (parse_cub(&game, av[1]) == -1)
		return (ft_cub_error(&game));
	ft_init_buffer(&game);
	load_texture(&game);
	init_img(&game);
	if (ac == 3 && ft_strcmp("--save", av[2]) == 0)
	{
		raycasting(&game);
		sprite_casting(&game);
		if (save_bmp(&game, game.width, game.height) == -1)
			return (-1);
	}
	else
		play_game(game);
	return (0);
}
