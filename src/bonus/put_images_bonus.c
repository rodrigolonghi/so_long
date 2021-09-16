/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 05:30:10 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/16 00:12:00 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	insert_image_bonus(t_game *game, int rows, int cols, char img_code)
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
	else if (img_code == 'O')
		mlx_put_image_to_window(game->mlx, game->win,
			game->opponent.img, 50 * cols, 50 * rows);
	else if (img_code == 'S')
		mlx_put_image_to_window(game->mlx, game->win,
			game->steps_counter.img, 50 * cols, 50 * rows);
	else
		throw_error_bonus("Invalid character provided");
}

int	put_images_bonus(t_game *game)
{
	int	rows;
	int	cols;

	rows = 0;
	while (rows < game->map.rows)
	{
		cols = 0;
		while (cols < game->map.cols)
		{
			insert_image_bonus(game, rows, cols,
				game->map.coordinates[rows][cols]);
			cols++;
		}
		rows++;
	}
	return (0);
}
