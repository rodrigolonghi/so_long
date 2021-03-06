/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_haszero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 05:11:14 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/09/11 05:17:25 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_haszero(int *s, int size)
{
	while (size > 0)
	{
		if (s[size - 1] == 0)
			return (1);
		size--;
	}
	return (0);
}
