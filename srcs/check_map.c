/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:53:54 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/11 05:17:00 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	check_map_characters2(char *aux, int cols, int *characters,
	t_game *game)
{
	if (aux[cols] == '0')
		characters[0]++;
	else if (aux[cols] == '1')
		characters[1]++;
	else if (aux[cols] == 'C')
		characters[2]++;
	else if (aux[cols] == 'E')
		characters[3]++;
	else if (aux[cols] == 'P')
		characters[4]++;
	else
		throw_error(game, "Invalid character on map");
	game->to_collect = characters[2];
}

void static	check_map_characters(t_game *game, char *map)
{
	int		fd;
	int		rows;
	int		cols;
	int		*characters;
	char	*aux;

	rows = 0;
	characters = ft_calloc(5, sizeof(int));
	fd = open(ft_strjoin("./maps/", map), O_RDWR);
	while (rows < game->map.rows && get_next_line(fd, &aux))
	{
		cols = 0;
		while (cols < game->map.cols && game->close_game == 0)
		{
			check_map_characters2(aux, cols, characters, game);
			cols++;
		}
		rows++;
	}
	if (game->close_game == 0 && ft_haszero(characters, 5))
		throw_error(game, ft_strjoin("Map must have at least one exit, one",
				" collectible and one starting position."));
	free(aux);
	free(characters);
	close(fd);
}

void static	check_map_walls(t_game *game, char *map)
{
	int		fd;
	int		rows;
	int		cols;
	char	*aux;

	rows = 0;
	fd = open(ft_strjoin("./maps/", map), O_RDWR);
	while (rows < game->map.rows && game->close_game == 0)
	{
		get_next_line(fd, &aux);
		cols = 0;
		while (cols < game->map.cols && game->close_game == 0)
		{
			if ((cols == 0 || cols == game->map.cols - 1
					|| rows == 0 || rows == game->map.rows - 1)
				&& aux[cols] != '1')
				throw_error(game, "Map must be closed/surrounded by walls");
			cols++;
		}
		rows++;
	}
	close(fd);
}

void static	count_map_size(t_game *game, char *map)
{
	int		fd;
	char	*aux;

	game->map.rows = 0;
	game->map.cols = -1;
	fd = open(ft_strjoin("./maps/", map), O_RDWR);
	while (get_next_line(fd, &aux) == 1)
	{
		if (game->map.cols == -1)
			game->map.cols = ft_strlen(aux);
		else if (game->map.cols != (int) ft_strlen(aux))
		{
			game->map.cols = -1;
			break ;
		}
		game->map.rows++;
	}
	if (game->map.cols != (int) ft_strlen(aux))
		game->map.cols = -1;
	if (game->map.cols <= 0 && game->map.rows <= 0)
		throw_error(game, "Map must be rectangular");
	game->map.rows++;
	if (aux != NULL)
		free(aux);
	close(fd);
}

void	check_map(t_game *game, char *map)
{
	if (game->close_game == 0)
		count_map_size(game, map);
	check_map_walls(game, map);
	check_map_characters(game, map);
}
