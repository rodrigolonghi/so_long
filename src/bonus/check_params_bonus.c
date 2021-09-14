/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:42:37 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/14 02:42:55 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_params_bonus(int argc, char *argv[])
{
	int	fd;

	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4) != 0)
			throw_error_bonus("You must enter a '.ber' file");
	}
	else
		throw_error_bonus("Invalid numbers of arguments");
	fd = open(ft_strjoin("./maps/", argv[1]), O_RDWR);
	if (fd < 0)
		throw_error_bonus("A valid file was not found");
	close(fd);
}
