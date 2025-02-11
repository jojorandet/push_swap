/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:56:27 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/11 22:22:05 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rot_a(t_stack *stack)
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
	printf("ra\n");
}

void	rot_b(t_stack *stack)
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
	printf("rb\n");
}

void	rot_rr(t_stack *stack)
{
	rot_a(stack);
	rot_b(stack);
}
