/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:40:01 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/18 19:53:34 by jrandet          ###   ########.fr       */
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
