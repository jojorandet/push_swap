/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_and_rev_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:51:20 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/03 17:27:42 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_stack *stack, t_string *string)
{
	int	temp;
	int	*cursor;

	cursor = stack->top;
	temp = *(cursor);
	while (cursor < (stack->end))
	{
		*(cursor) = *(cursor + 1);
		cursor++;
	}
	*(cursor) = temp;
	append_result_string(string, 'r');
	append_result_string(string, 'a');
	append_result_string(string, '\n');
}

void	rot_b(t_stack *stack, t_string *string)
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
	append_result_string(string, 'r');
	append_result_string(string, 'b');
	append_result_string(string, '\n');
}

void	rev_rot_a(t_stack *stack, t_string *string)
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
	append_result_string(string, 'r');
	append_result_string(string, 'r');
	append_result_string(string, 'a');
	append_result_string(string, '\n');
}

void	rev_rot_b(t_stack *stack, t_string *string)
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
	append_result_string(string, 'r');
	append_result_string(string, 'r');
	append_result_string(string, 'b');
	append_result_string(string, '\n');
}
