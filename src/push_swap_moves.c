/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:13:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/01 16:12:44 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_function(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_a(t_stack *stack)
{
	if (stack->end - stack->top < 2)
		return ;
	swap_function(stack->top, (stack->top + 1));
}

void	swap_b(t_stack *stack)
{
	if (stack->top - stack->values < 2)
		return ;
	swap_function((stack->top - 1), (stack->top - 2));
}

void	push_a(t_stack *stack)
{
	if (stack->top == stack->values)
		return ;
	stack->top--;
}

void	push_b(t_stack *stack)
{
	if (stack->end == (stack->top - 1))
		return ;
	stack->top++;
}
