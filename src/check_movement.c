/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:40:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/13 18:25:33 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_movement(t_game *game, int x, int y)
{
	x = game->player_pos.x + x;
	y = game->player_pos.y + y;
	if (game->map.coordinates[x][y] == '0'
		|| game->map.coordinates[x][y] == 'P')
		return (1);
	else if (game->map.coordinates[x][y] == 'C')
	{
		game->to_collect--;
		game->map.coordinates[x][y] = '0';
		return (1);
	}
	else if (game->map.coordinates[x][y] == 'E')
	{
		if (game->to_collect == 0)
		{
			printf("YOU WIN!\n");
			exit(0);
		}
		printf("You need to collect %d more gems before leaving!\n",
			game->to_collect);
	}
	return (0);
}
