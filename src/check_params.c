/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 04:18:40 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/13 18:34:24 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_params(int argc, char *argv[])
{
	int	fd;

	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4) != 0)
			throw_error("You must enter a '.ber' file");
	}
	else
		throw_error("Invalid numbers of arguments");
	fd = open(ft_strjoin("./maps/", argv[1]), O_RDWR);
	if (fd < 0)
		throw_error("A valid file was not found");
	close(fd);
}
