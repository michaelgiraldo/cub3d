/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:18:32 by mg                #+#    #+#             */
/*   Updated: 2020/06/17 12:32:02 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list ’lst’ and applies the function
** ’f’ to the content of each element. Creates a new
** list resulting of the successive applications of
** the function ’f’. The ’del’ function is used to
** delete the content of an element if needed.
**
** #1. The adress of a pointer to an element.
** #2. The adress of the function used to iterate on the list.
** #3. The adress of the function used to delete the content of an element
** 	 	, if needed
**
** RETURN: The new list. NULL if the allocation fails.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *new_element;
	t_list *current;

	current = lst;
	while (current)
	{
		if (!(new_element = ft_lstnew(f(current->content))))
		{
			ft_lstclear(&new_list, del);
			ft_lstclear(&new_element, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		current = current->next;
	}
	return (new_list);
}
