/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation_operations.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:40:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/18 19:45:57 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_element_position(t_stack *stack, int n)
{
	int	*cursor;
	int	i;

	i = 0;
	cursor = stack->top;
	while (cursor[i] != n && cursor + i <= stack->end)
		i++;
	return (i);
}

void	push_index_to_b(t_stack *stack, int index)
{
	int	i;
	int	n;

	i = find_element_position(stack, index);
	if (i > (stack->len_a / 2))
	{
		n = stack->len_a - i;
		while (n--)
			rev_rot_a(stack);
	}
	else
	{
		while (i--)
			rot_a(stack);
	}
	push_b(stack);
}
