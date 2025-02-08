/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:40:01 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/08 12:32:09 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->values)
		{
			free(stack->values);
			stack->values = NULL;
		}
	}
}


//analogy of the bookshelf to help me understand. I bought the bookshelf (allocated memory for it)
//it has a fixed number of slots 
//i did not buy new shelves when pointing the pointers top end to the elements within the bookshelf 
//therefore when freeing I only free the bookshelf. 
//if i freed the top and end value, i would essentially return the bookmarkes to the bookshelf store. 