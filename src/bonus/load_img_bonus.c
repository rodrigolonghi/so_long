/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:51:42 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/14 02:48:56 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
}
