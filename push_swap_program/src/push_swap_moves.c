/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:13:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/07 16:30:51 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_function(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_a(t_stack *stack, t_string *string)
{
	if (stack->end - stack->top < 2)
		return ;
	swap_function(stack->top, (stack->top + 1));
	append_result_string(string, 's');
	append_result_string(string, 'a');
	append_result_string(string, '\n');
}

void	swap_b(t_stack *stack, t_string *string)
{
	if (stack->top - stack->values < 2)
		return ;
	swap_function((stack->top - 1), (stack->top - 2));
	append_result_string(string, 's');
	append_result_string(string, 'b');
	append_result_string(string, '\n');
}

void	push_a(t_stack *stack, t_string *string)
{
	if (stack->top == stack->values)
		return ;
	stack->top--;
	append_result_string(string, 'p');
	append_result_string(string, 'a');
	append_result_string(string, '\n');
}

void	push_b(t_stack *stack, t_string *string)
{
	if (stack->end == (stack->top - 1))
		return ;
	stack->top++;
	append_result_string(string, 'p');
	append_result_string(string, 'b');
	append_result_string(string, '\n');
}
