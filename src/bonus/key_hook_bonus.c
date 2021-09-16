/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 00:57:16 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/16 00:23:12 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void static	go_right(t_game *g)
{
	if (check_movement_bonus(g, 0, 1))
	{
		insert_image_bonus(g, g->player_pos.x, g->player_pos.y, '0');
		walk_animation_bonus(g, g->player_pos.x, g->player_pos.y + 1, 'R');
		g->map.coordinates[g->player_pos.x][g->player_pos.y] = '0';
		g->player_pos.y++;
		g->map.coordinates[g->player_pos.x][g->player_pos.y] = 'P';
		g->steps++;
		insert_image_bonus(g, 0, 0, 'S');
		mlx_string_put(g->mlx, g->win, 20, 30, 0xFFFFFF, ft_itoa(g->steps));
	}
}

void static	go_left(t_game *g)
{
	if (check_movement_bonus(g, 0, -1))
	{
		insert_image_bonus(g, g->player_pos.x, g->player_pos.y, '0');
		walk_animation_bonus(g, g->player_pos.x, g->player_pos.y - 1, 'L');
		g->map.coordinates[g->player_pos.x][g->player_pos.y] = '0';
		g->player_pos.y--;
		g->map.coordinates[g->player_pos.x][g->player_pos.y] = 'P';
		g->steps++;
		insert_image_bonus(g, 0, 0, 'S');
		mlx_string_put(g->mlx, g->win, 20, 30, 0xFFFFFF, ft_itoa(g->steps));
	}
}

void static	go_down(t_game *g)
{
	if (check_movement_bonus(g, 1, 0))
	{
		insert_image_bonus(g, g->player_pos.x, g->player_pos.y, '0');
		walk_animation_bonus(g, g->player_pos.x + 1, g->player_pos.y, 'D');
		g->map.coordinates[g->player_pos.x][g->player_pos.y] = '0';
		g->player_pos.x++;
		g->map.coordinates[g->player_pos.x][g->player_pos.y] = 'P';
		g->steps++;
		insert_image_bonus(g, 0, 0, 'S');
		mlx_string_put(g->mlx, g->win, 20, 30, 0xFFFFFF, ft_itoa(g->steps));
	}
}

void static	go_up(t_game *g)
{
	if (check_movement_bonus(g, -1, 0))
	{
		insert_image_bonus(g, g->player_pos.x, g->player_pos.y, '0');
		walk_animation_bonus(g, g->player_pos.x - 1, g->player_pos.y, 'U');
		g->map.coordinates[g->player_pos.x][g->player_pos.y] = '0';
		g->player_pos.x--;
		g->map.coordinates[g->player_pos.x][g->player_pos.y] = 'P';
		g->steps++;
		insert_image_bonus(g, 0, 0, 'S');
		mlx_string_put(g->mlx, g->win, 20, 30, 0xFFFFFF, ft_itoa(g->steps));
	}
}

int	key_hook_bonus(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == ESC)
		close_game_bonus(game);
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
