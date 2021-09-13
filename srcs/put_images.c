/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 05:30:10 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/13 04:35:23 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	insert_image(t_game *game, int rows, int cols, char img_code)
{
	if (img_code == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->empty.img, 50 * cols, 50 * rows);
	else if (img_code == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, 50 * cols, 50 * rows);
	else if (img_code == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect.img, 50 * cols, 50 * rows);
	else if (img_code == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, 50 * cols, 50 * rows);
	else if (img_code == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img, 50 * cols, 50 * rows);
	else
		throw_error(game, "Invalid character provided");
}

int	put_images(t_game *game)
{
	int	rows;
	int	cols;

	rows = 0;
	while (rows < game->map.rows)
	{
		cols = 0;
		while (cols < game->map.cols)
		{
			insert_image(game, rows, cols, game->map.coordinates[rows][cols]);
			cols++;
		}
		rows++;
	}
	return (0);
}
