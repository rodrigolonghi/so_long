/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:40:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/16 19:23:13 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	end(char *msg)
{
	printf("%s\n", msg);
	exit(0);
}

int	check_movement(t_game *g, int x, int y)
{
	x = g->player_pos.x + x;
	y = g->player_pos.y + y;
	if (g->map.coordinates[x][y] == '0' || g->map.coordinates[x][y] == 'P')
		return (1);
	else if (g->map.coordinates[x][y] == 'C')
	{
		g->to_collect--;
		g->map.coordinates[x][y] = '0';
		return (1);
	}
	else if (g->map.coordinates[x][y] == 'E')
	{
		if (g->to_collect == 0)
			end("YOU WIN!");
		printf("You need to collect %d more gems before leaving!\n",
			g->to_collect);
	}
	return (0);
}
