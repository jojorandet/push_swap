/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:51:20 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/17 17:22:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	apply_rev_rot_a(t_stack *stack)
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
}

static void	apply_rev_rot_b(t_stack *stack)
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
}

void	rev_rot_a(t_stack *stack)
{
	apply_rev_rot_a(stack);
	ft_putstr("rra\n");
}

void	rev_rot_b(t_stack *stack)
{
	apply_rev_rot_b(stack);
	ft_putstr("rrb\n");
}

void	rev_rot_rr(t_stack *stack)
{
	apply_rev_rot_a(stack);
	apply_rev_rot_b(stack);
	ft_putstr("rrr\n");
}