/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:13:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/31 17:54:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_function(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_a(t_stack *stack)
{ 
	if (stack->end - stack->cursor < 2)
		return ;
	swap_function(stack->cursor, (stack->cursor + 1));
}

void	swap_b(t_stack *stack)
{
	if (stack->cursor - stack->values < 2)
		return ;
	swap_function((stack->cursor - 1), (stack->cursor - 2));
}


void	push_a(t_stack *stack)
{
	if (stack->cursor == stack->values)// can rewrite if equal :)
		return ;
	stack->cursor--;
}

void	push_b(t_stack *stack)
{
	if (stack->end == (stack->cursor - 1))
		return ;
	stack->cursor++;
}
