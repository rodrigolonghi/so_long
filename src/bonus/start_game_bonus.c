/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 01:31:45 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/16 19:22:05 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	start_win_bonus(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.cols * 50,
			game->map.rows * 50, "so_long");
	game->steps = 0;
	game->look = 'R';
	load_image_bonus(game);
	put_images_bonus(game);
}

void	start_game_bonus(t_game *game, int argc, char *argv[])
{
	check_params_bonus(argc, argv);
	check_map_bonus(game, argv[1]);
	start_win_bonus(game);
	mlx_key_hook(game->win, key_hook_bonus, game);
	mlx_hook(game->win, 17, 0, close_game_bonus, game);
	mlx_expose_hook(game->win, put_images_bonus, game);
	mlx_loop(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	close_game_bonus(game);
	free(game->mlx);
}
