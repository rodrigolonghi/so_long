/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 02:26:10 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/13 17:26:22 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.coordinates)
	{
		while (i < game->map.rows)
		{
			free(game->map.coordinates[i]);
			i++;
		}
		free(game->map.coordinates);
	}
}

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}
