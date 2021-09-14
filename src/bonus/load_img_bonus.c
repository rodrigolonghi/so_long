/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:51:42 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/14 03:35:06 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void static	load_walk_animation2(t_game *g)
{
	g->playerRun2.img = mlx_xpm_file_to_image(g->mlx,
			"img/character/run2.xpm", &g->playerRun2.width,
			&g->playerRun2.height);
	g->playerRun2.addr = mlx_get_data_addr(g->playerRun2.img,
			&g->playerRun2.bpp, &g->playerRun2.line_length,
			&g->playerRun2.endian);
	g->playerRun2Left.img = mlx_xpm_file_to_image(g->mlx,
			"img/character/run2Left.xpm", &g->playerRun2Left.width,
			&g->playerRun2Left.height);
	g->playerRun2Left.addr = mlx_get_data_addr(g->playerRun2Left.img,
			&g->playerRun2Left.bpp, &g->playerRun2Left.line_length,
			&g->playerRun2Left.endian);
}

void static	load_walk_animation(t_game *g)
{
	g->playerLeft.img = mlx_xpm_file_to_image(g->mlx,
			"img/character/idleLeft.xpm", &g->playerLeft.width,
			&g->playerLeft.height);
	g->playerLeft.addr = mlx_get_data_addr(g->playerLeft.img,
			&g->playerLeft.bpp, &g->playerLeft.line_length,
			&g->playerLeft.endian);
	g->playerRun1.img = mlx_xpm_file_to_image(g->mlx,
			"img/character/run1.xpm", &g->playerRun1.width,
			&g->playerRun1.height);
	g->playerRun1.addr = mlx_get_data_addr(g->playerRun1.img,
			&g->playerRun1.bpp, &g->playerRun1.line_length,
			&g->playerRun1.endian);
	g->playerRun1Left.img = mlx_xpm_file_to_image(g->mlx,
			"img/character/run1Left.xpm", &g->playerRun1Left.width,
			&g->playerRun1Left.height);
	g->playerRun1Left.addr = mlx_get_data_addr(g->playerRun1Left.img,
			&g->playerRun1Left.bpp, &g->playerRun1Left.line_length,
			&g->playerRun1Left.endian);
	load_walk_animation2(g);
}

void	load_image_bonus(t_game *g)
{
	g->player.img = mlx_xpm_file_to_image(g->mlx, "img/character/idle.xpm",
			&g->player.width, &g->player.height);
	g->player.addr = mlx_get_data_addr(g->player.img, &g->player.bpp,
			&g->player.line_length, &g->player.endian);
	g->collect.img = mlx_xpm_file_to_image(g->mlx, "img/collect/gem.xpm",
			&g->collect.width, &g->collect.height);
	g->collect.addr = mlx_get_data_addr(g->collect.img, &g->collect.bpp,
			&g->collect.line_length, &g->collect.endian);
	g->wall.img = mlx_xpm_file_to_image(g->mlx, "img/wall/wall.xpm",
			&g->wall.width, &g->wall.height);
	g->wall.addr = mlx_get_data_addr(g->wall.img, &g->wall.bpp,
			&g->wall.line_length, &g->wall.endian);
	g->empty.img = mlx_xpm_file_to_image(g->mlx, "img/floor/sand.xpm",
			&g->empty.width, &g->empty.height);
	g->empty.addr = mlx_get_data_addr(g->empty.img, &g->empty.bpp,
			&g->empty.line_length, &g->empty.endian);
	g->exit.img = mlx_xpm_file_to_image(g->mlx, "img/exit/exit.xpm",
			&g->exit.width, &g->exit.height);
	g->exit.addr = mlx_get_data_addr(g->exit.img, &g->exit.bpp,
			&g->exit.line_length, &g->exit.endian);
	g->opponent.img = mlx_xpm_file_to_image(g->mlx, "img/opponent/opponent.xpm",
			&g->opponent.width, &g->opponent.height);
	g->opponent.addr = mlx_get_data_addr(g->opponent.img, &g->opponent.bpp,
			&g->opponent.line_length, &g->opponent.endian);
	load_walk_animation(g);
}
