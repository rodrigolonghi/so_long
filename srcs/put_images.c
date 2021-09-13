/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 05:30:10 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/13 02:19:41 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	put_images2(char *aux, int cols, int rows, t_game *game)
{
	if (aux[cols] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, 50 * cols, 50 * rows);
	else if (aux[cols] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect.img, 50 * cols, 50 * rows);
	else if (aux[cols] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, 50 * cols, 50 * rows);
	else if (aux[cols] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img, 50 * cols, 50 * rows);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->empty.img, 50 * cols, 50 * rows);
}

void	put_images(t_game *game, char *map)
{
	int		fd;
	int		rows;
	int		cols;
	char	*aux;

	rows = 0;
	fd = open(ft_strjoin("./maps/", map), O_RDWR);
	while (rows < game->map.rows)
	{
		cols = 0;
		get_next_line(fd, &aux);
		while (cols < game->map.cols && game->close_game == 0)
		{
			put_images2(aux, cols, rows, game);
			cols++;
		}
		rows++;
	}
	free(aux);
	close(fd);
}
