/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:15:22 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/05/27 01:48:56 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elemet;

	new_elemet = (t_list *)malloc(sizeof(t_list));
	if (!new_elemet)
		return (NULL);
	new_elemet->content = content;
	new_elemet->next = NULL;
	return (new_elemet);
}
