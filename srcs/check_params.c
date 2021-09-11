/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 04:18:40 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/11 04:24:03 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_params(t_game *game, int argc, char *argv[])
{
	game->close_game = 0;
	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4) != 0)
			throw_error(game, "You must enter a '.ber' file");
	}
	else
		throw_error(game, "Invalid numbers of arguments");
}
