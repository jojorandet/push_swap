/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:40:01 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/05 10:41:03 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->values && stack->top)
		{
			free(stack->top);
			stack->top = NULL;
		}
		free(stack->values);
		stack->values = NULL;
	}
}
