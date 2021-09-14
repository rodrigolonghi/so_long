/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 01:36:46 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/14 02:54:39 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void static	check_map_characters_bonus2(char *aux, int *rows_n_cols,
	int *characters, t_game *game)
{
	if (aux[rows_n_cols[1]] == '0')
		characters[0]++;
	else if (aux[rows_n_cols[1]] == '1')
		characters[1]++;
	else if (aux[rows_n_cols[1]] == 'C')
		characters[2]++;
	else if (aux[rows_n_cols[1]] == 'E')
		characters[3]++;
	else if (aux[rows_n_cols[1]] == 'P')
	{
		game->player_pos.x = rows_n_cols[0];
		game->player_pos.y = rows_n_cols[1];
		characters[5]++;
	}
	else if (aux[rows_n_cols[1]] == 'O')
		characters[4]++;
	else
		throw_error_bonus("Invalid character on map");
}

void static	check_map_characters_bonus(t_game *game, int *characters)
{
	int		*rows_n_cols;

	rows_n_cols = ft_calloc(2, sizeof(int));
	while (rows_n_cols[0] < game->map.rows)
	{
		rows_n_cols[1] = 0;
		while (rows_n_cols[1] < game->map.cols)
		{
			check_map_characters_bonus2(game->map.coordinates[rows_n_cols[0]],
				rows_n_cols, characters, game);
			rows_n_cols[1]++;
		}
		rows_n_cols[0]++;
	}
	free(rows_n_cols);
}

void	check_map_walls_bonus(t_game *game, char *map)
{
	int		fd;
	int		rows;
	int		cols;

	rows = 0;
	fd = open(ft_strjoin("./maps/", map), O_RDWR);
	while (rows < game->map.rows)
	{
		get_next_line(fd, &game->map.coordinates[rows]);
		cols = 0;
		while (cols < game->map.cols)
		{
			if ((cols == 0 || cols == game->map.cols - 1
					|| rows == 0 || rows == game->map.rows - 1)
				&& game->map.coordinates[rows][cols] != '1')
				throw_error_bonus("Map must be closed/surrounded by walls");
			cols++;
		}
		rows++;
	}
	close(fd);
}

void	count_map_size_bonus(t_game *game, char *map)
{
	int		fd;
	char	*aux;

	game->map.rows = 0;
	game->map.cols = -1;
	fd = open(ft_strjoin("./maps/", map), O_RDWR);
	while (get_next_line(fd, &aux) == 1)
	{
		if (game->map.cols == -1)
			game->map.cols = (int) ft_strlen(aux);
		else if (game->map.cols != (int) ft_strlen(aux))
		{
			game->map.cols = -1;
			break ;
		}
		game->map.rows++;
	}
	if (game->map.cols != (int) ft_strlen(aux) && game->map.cols != -1)
		game->map.cols = -1;
	if (game->map.cols <= 0 || game->map.rows <= 0)
		throw_error_bonus("Map must be rectangular");
	game->map.rows++;
	if (aux != NULL)
		free(aux);
	close(fd);
}

void	check_map_bonus(t_game *game, char *map)
{
	int	*characters;

	characters = ft_calloc(6, sizeof(int));
	count_map_size_bonus(game, map);
	game->map.coordinates = malloc(sizeof(char *) * game->map.rows);
	check_map_walls_bonus(game, map);
	check_map_characters_bonus(game, characters);
	if (ft_haszero(characters, 5) == 1)
		throw_error_bonus(ft_strjoin("Map must have at least one exit, one",
				" collectible, one opponent and one starting position."));
	if (characters[5] != 1)
		throw_error_bonus("You need to put exactly one player on the map");
	game->to_collect = characters[2];
	free(characters);
}
