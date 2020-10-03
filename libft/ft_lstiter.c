/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:28:14 by mg                #+#    #+#             */
/*   Updated: 2020/06/17 12:32:02 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list ’lst’ and applies the function
** ’f’ to the content of each element.
** #1. The adress of a pointer to an element.
** #2. The adress of the function used to iterate on
** the list.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *current;
	t_list *next;

	current = lst;
	while (current)
	{
		next = current->next;
		f(current->content);
		current = next;
	}
}
