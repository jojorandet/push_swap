/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_and_rev_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:51:20 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/31 18:54:14 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_stack *stack)
{
	int	temp;
	int	*cursor_temp;

	cursor_temp = stack->cursor;
	temp = *(cursor_temp);
	while (cursor_temp < (stack->end))
	{
		*(cursor_temp) = *(cursor_temp + 1);
		cursor_temp++;
	}
	*(cursor_temp) = temp;
}

void	rot_b(t_stack *stack)
{
	int temp;
	int	*cursor_temp;

	cursor_temp = (stack->cursor - 1);
	temp = *cursor_temp;
	while (cursor_temp > stack->values)
	{
		*cursor_temp = *(cursor_temp - 1);
		cursor_temp--;
	}
	*cursor_temp = temp;
}

void	rev_rot_a(t_stack *stack)
{
	int	temp;
	int	*cursor_temp;

	temp = *(stack->end);
	cursor_temp = (stack->end);
	while (cursor_temp > stack->cursor)
	{
		*(cursor_temp) = *(cursor_temp - 1);
		cursor_temp--;
	}
	*cursor_temp = temp;
}
