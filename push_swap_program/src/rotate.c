/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:56:27 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/17 19:24:34 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	apply_rot_a(t_stack *stack)
{
	int	temp;
	int	*cursor_rot;

	cursor_rot = stack->top;
	temp = *(cursor_rot);
	while (cursor_rot < (stack->end))
	{
		*(cursor_rot) = *(cursor_rot + 1);
		cursor_rot++;
	}
	*(stack->end) = temp;
}

static void	apply_rot_b(t_stack *stack)
{
	int	temp;
	int	*cursor;

	cursor = (stack->top - 1);
	temp = *cursor;
	while (cursor > stack->values)
	{
		*cursor = *(cursor - 1);
		cursor--;
	}
	*cursor = temp;
}

void	rot_a(t_stack *stack)
{
	apply_rot_a(stack);
	ft_putstr("ra\n");
}

void	rot_b(t_stack *stack)
{
	apply_rot_b(stack);
	ft_putstr("rb\n");
}

void	rot_rr(t_stack *stack)
{
	apply_rot_a(stack);
	apply_rot_b(stack);
	ft_putstr("rr\n");
}