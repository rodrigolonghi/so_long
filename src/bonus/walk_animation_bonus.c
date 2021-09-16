/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 03:01:22 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/16 19:22:20 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	walk_animation_bonus2(t_game *g, int x, int y, char direction)
{
	if (g->steps % 2 == 0)
	{
		if (direction == 'R')
		{
			mlx_put_image_to_window(g->mlx, g->win,
				g->playerRun2.img, 50 * y, 50 * x);
			g->look = 'R';
		}
		else if (direction == 'L')
		{
			mlx_put_image_to_window(g->mlx, g->win,
				g->playerRun2Left.img, 50 * y, 50 * x);
			g->look = 'L';
		}
		else
		{
			if (g->look == 'R')
				mlx_put_image_to_window(g->mlx, g->win,
					g->playerRun2.img, 50 * y, 50 * x);
			else
				mlx_put_image_to_window(g->mlx, g->win,
					g->playerRun2Left.img, 50 * y, 50 * x);
		}
	}
}

void	walk_animation_bonus(t_game *g, int x, int y, char direction)
{
	if (g->steps % 2 != 0)
	{
		if (direction == 'R')
		{
			mlx_put_image_to_window(g->mlx, g->win,
				g->playerRun1.img, 50 * y, 50 * x);
			g->look = 'R';
		}
		else if (direction == 'L')
		{
			mlx_put_image_to_window(g->mlx, g->win, g->playerRun1Left.img,
				50 * y, 50 * x);
			g->look = 'L';
		}
		else
		{
			if (g->look == 'R')
				mlx_put_image_to_window(g->mlx, g->win,
					g->playerRun1.img, 50 * y, 50 * x);
			else
				mlx_put_image_to_window(g->mlx, g->win,
					g->playerRun1Left.img, 50 * y, 50 * x);
		}
	}
	walk_animation_bonus2(g, x, y, direction);
}
