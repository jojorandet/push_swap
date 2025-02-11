/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:51:20 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/11 20:01:22 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rev_rot_a(t_stack *stack)
{
	int	temp;
	int	*cursor;

	temp = *(stack->end);
	cursor = (stack->end);
	while (cursor > stack->top)
	{
		*(cursor) = *(cursor - 1);
		cursor--;
	}
	*cursor = temp;
	printf("rra\n");
}

void	rev_rot_b(t_stack *stack)
{
	int	temp;
	int	*cursor;

	temp = *(stack->values);
	cursor = (stack->values);
	while (cursor < (stack->top - 1))
	{
		*cursor = *(cursor + 1);
		cursor++;
	}
	*cursor = temp;
	printf("rrb\n");
}

void	rev_rot_rr(t_stack *stack)
{
	rev_rot_a(stack);
	rev_rot_b(stack);
}