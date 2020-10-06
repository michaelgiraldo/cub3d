/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:18:05 by mg                #+#    #+#             */
/*   Updated: 2020/06/17 12:31:53 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the number of elements in a list.
*/

int	ft_lstsize(t_list *lst)
{
	t_list *current;
	t_list *next;
	size_t count;

	current = lst;
	count = 0;
	while (current)
	{
		next = current->next;
		current = next;
		++count;
	}
	return (count);
}
