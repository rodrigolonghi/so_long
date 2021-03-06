/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 00:57:16 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/16 19:23:48 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	go_right(t_game *game)
{
	if (check_movement(game, 0, 1))
	{
		insert_image(game, game->player_pos.x, game->player_pos.y, '0');
		insert_image(game, game->player_pos.x, game->player_pos.y + 1, 'P');
		game->map.coordinates[game->player_pos.x][game->player_pos.y] = '0';
		game->player_pos.y++;
		game->map.coordinates[game->player_pos.x][game->player_pos.y] = 'P';
		game->steps++;
		printf("%d\n", game->steps);
	}
}

static void	go_left(t_game *game)
{
	if (check_movement(game, 0, -1))
	{
		insert_image(game, game->player_pos.x, game->player_pos.y, '0');
		insert_image(game, game->player_pos.x, game->player_pos.y - 1, 'P');
		game->map.coordinates[game->player_pos.x][game->player_pos.y] = '0';
		game->player_pos.y--;
		game->map.coordinates[game->player_pos.x][game->player_pos.y] = 'P';
		game->steps++;
		printf("%d\n", game->steps);
	}
}

static void	go_down(t_game *game)
{
	if (check_movement(game, 1, 0))
	{
		insert_image(game, game->player_pos.x, game->player_pos.y, '0');
		insert_image(game, game->player_pos.x + 1, game->player_pos.y, 'P');
		game->map.coordinates[game->player_pos.x][game->player_pos.y] = '0';
		game->player_pos.x++;
		game->map.coordinates[game->player_pos.x][game->player_pos.y] = 'P';
		game->steps++;
		printf("%d\n", game->steps);
	}
}

static void	go_up(t_game *game)
{
	if (check_movement(game, -1, 0))
	{
		insert_image(game, game->player_pos.x, game->player_pos.y, '0');
		insert_image(game, game->player_pos.x - 1, game->player_pos.y, 'P');
		game->map.coordinates[game->player_pos.x][game->player_pos.y] = '0';
		game->player_pos.x--;
		game->map.coordinates[game->player_pos.x][game->player_pos.y] = 'P';
		game->steps++;
		printf("%d\n", game->steps);
	}
}

int	key_hook(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == ESC)
		close_game(game);
	if (key == UP || key == ARROW_UP)
		go_up(game);
	else if (key == DOWN || key == ARROW_DOWN)
		go_down(game);
	else if (key == LEFT || key == ARROW_LEFT)
		go_left(game);
	else if (key == RIGHT || key == ARROW_RIGHT)
		go_right(game);
	return (0);
}
