/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:59:05 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/11 00:56:23 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win.ref = mlx_new_window(game->mlx, 600, 500, "so_long");
	load_image(game);
	for(int i = 0; i < 600 / 50; i++)
	{
		for(int j =0; j< 500 / 50; j++)
		{
			mlx_put_image_to_window(game->mlx, game->win.ref, game->empty.img, 50 * i, 50 * j);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win.ref, game->player.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win.ref, game->collect.img, 0, 50);
	mlx_put_image_to_window(game->mlx, game->win.ref, game->wall.img, 0, 100);
	mlx_put_image_to_window(game->mlx, game->win.ref, game->empty.img, 50, 0);
	mlx_put_image_to_window(game->mlx, game->win.ref, game->exit.img, 100, 0);
	mlx_loop(game->mlx);
}
 