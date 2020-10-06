/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:27:48 by mg                #+#    #+#             */
/*   Updated: 2020/06/17 12:32:03 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter an element and frees the
** memory of the element’s content using the function
** ’del’ given as a parameter and free the element.
** The memory of ’next’ must not be freed.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list *current;
	t_list *next;

	current = lst;
	next = current->next;
	del(current->content);
	free(current);
	lst = next;
}
