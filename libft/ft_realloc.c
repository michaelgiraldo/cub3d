/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:27:09 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/06/17 12:32:01 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	SOURCE: command "man ralloc"
**	https://www.gnu.org/software/libc/manual/html_node/Changing-Block-Size.html
**
**	-------------------------------------------------------------------------
**	DESCRIPTION
**	-------------------------------------------------------------------------
**	The realloc() function allocate memory. The allocated memory is aligned
**	such that it can be used for any data type, including AltiVec- and
**	SSE-related types.
**
**	The realloc() function tries to change the size of the allocation pointed
**	to by ptr to size, and returns ptr.  If there is not enough room to enlarge
**	the memory allocation pointed to by ptr, realloc() creates a new allocation,
**	copies as much of the old data pointed to by ptr as will fit to the new
**	allocation, frees the old allocation, and returns a pointer to the allocated
**	memory.  If ptr is NULL, realloc() is identical to a call to malloc() for
**	size bytes.  If size is zero and ptr is not NULL, a new, minimum sized
**	object is allocated and the original object is freed.
**
**	When extending a region allocated with calloc(3), realloc(3) does not
**	guarantee that the additional memory is also zero-filled.
**
**	-------------------------------------------------------------------------
**		RETURN VALUES
**	-------------------------------------------------------------------------
**	If successful, realloc() function return a pointer to allocated memory.
**	If there is an error, they return a NULL pointer and set errno to ENOMEM.
**
**	For realloc(), the input pointer is still valid if reallocation failed.
*/

void	*ft_realloc(void *ptr, size_t size)
{
	void *newptr;

	if (!ptr)
		return (malloc(size));
	else if (!size)
		return (malloc(120));
	else if (!(newptr = malloc(size)))
		return (NULL);
	ft_memmove(newptr, ptr, size);
	free(ptr);
	ptr = newptr;
	return (newptr);
}
