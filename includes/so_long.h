/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 00:54:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/10 00:39:04 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		cols;
	int		lines;
	char	**arr;

}	t_map;

typedef struct s_window
{
	void	*ref;
	int		x;
	int		y;
}	t_window;

typedef struct s_sprite
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}	t_sprite;

typedef struct s_game
{
	void		*mlx;
	t_window	win;
	t_sprite	player;
	t_sprite	collect;
	t_sprite	wall;
	t_sprite	empty;
	t_sprite	exit;
	t_map		map;
	int			to_collect;
	int			steps;

}	t_game;

void	load_image(t_game *game);
void	start_game(t_game *game);

#endif
