/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 00:54:23 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/14 02:37:18 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define LEFT			0x61
# define RIGHT			0x64
# define DOWN			0x73
# define UP				0x77
# define ARROW_LEFT		0xff51
# define ARROW_UP		0xff52
# define ARROW_RIGHT	0xff53
# define ARROW_DOWN		0xff54
# define ESC			0xff1b

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		cols;
	int		rows;
	char	**coordinates;
}	t_map;

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
	void		*win;
	t_sprite	player;
	t_sprite	collect;
	t_sprite	wall;
	t_sprite	empty;
	t_sprite	exit;
	t_map		map;
	t_pos		player_pos;
	int			to_collect;
	int			steps;
}	t_game;

void	load_image(t_game *game);
void	start_game(t_game *game, int argc, char *argv[]);
void	throw_error(char *e);
void	check_params(int argc, char *argv[]);
void	check_map(t_game *game, char *map);
int		put_images(t_game *game);
int		key_hook(int key, void *param);
void	insert_image(t_game *game, int rows, int cols, char img_code);
int		close_game(t_game *game);
int		check_movement(t_game *game, int x, int y);
void	count_map_size(t_game *game, char *map);
void	check_map_walls(t_game *game, char *map);

#endif
