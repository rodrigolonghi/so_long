/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:59:05 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/11 05:33:43 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(t_game *game, int argc, char *argv[])
{
	check_params(game, argc, argv);
	check_map(game, argv[1]);
	if (game->close_game == 0)
	{
		game->mlx = mlx_init();
		game->win.ref = mlx_new_window(game->mlx, game->map.cols * 50,
				game->map.rows * 50, "so_long");
		load_image(game);
		put_images(game, argv[1]);
		mlx_loop(game->mlx);
	}
}
