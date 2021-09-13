/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:59:05 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/13 04:46:43 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	start_win(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.cols * 50,
			game->map.rows * 50, "so_long");
	load_image(game);
	put_images(game);
}

void	start_game(t_game *game, int argc, char *argv[])
{
	check_params(game, argc, argv);
	check_map(game, argv[1]);
	if (game->close_game == 0)
	{
		start_win(game);
		mlx_key_hook(game->win, move_hook, game);
		mlx_loop(game->mlx);
	}
}

// for (int x = 0; x < game->map.rows; x++)
// 	{
// 		for(int y = 0; y < game->map.cols; y++)
// 		{
// 			printf("%c", game->map.coordinates[x][y]);
// 		}
// 		printf("\n");
// 	}