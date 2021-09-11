/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 00:54:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/11 05:32:55 by rfelipe-         ###   ########.fr       */
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
	int		rows;
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
	t_pos		player_pos;
	int			to_collect;
	int			steps;
	int			close_game;
}	t_game;

void	load_image(t_game *game);
void	start_game(t_game *game, int argc, char *argv[]);
void	throw_error(t_game *game, char *e);
void	check_params(t_game *game, int argc, char *argv[]);
void	check_map(t_game *game, char *map);
void	put_images(t_game *game, char *map);

#endif
