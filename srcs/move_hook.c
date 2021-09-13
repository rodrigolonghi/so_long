/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 00:57:16 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/13 04:45:22 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	go_left(t_game *game)
{
	insert_image(game, game->player_pos.x, game->player_pos.y, '0');
	insert_image(game, game->player_pos.x, game->player_pos.y - 1, 'P');
	game->player_pos.y--;
}

void static	go_right(t_game *game)
{
	insert_image(game, game->player_pos.x, game->player_pos.y, '0');
	insert_image(game, game->player_pos.x, game->player_pos.y + 1, 'P');
	game->player_pos.y++;
}

void static	go_down(t_game *game)
{
	insert_image(game, game->player_pos.x, game->player_pos.y, '0');
	insert_image(game, game->player_pos.x + 1, game->player_pos.y, 'P');
	game->player_pos.x++;
}

void static	go_up(t_game *game)
{
	insert_image(game, game->player_pos.x, game->player_pos.y, '0');
	insert_image(game, game->player_pos.x - 1, game->player_pos.y, 'P');
	game->player_pos.x--;
}

int	move_hook(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	// if (key == ESC)
	// 	close_game(game);
	if (key == UP)
		go_up(game);
	else if (key == DOWN)
		go_down(game);
	else if (key == RIGHT)
		go_right(game);
	else if (key == LEFT)
		go_left(game);
	return (0);
}
