/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:13:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/31 12:13:38 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{ 
	int	temp;

	temp = *(stack->cursor);
	*(stack->cursor) = *(stack->cursor + 1);
	*(stack->cursor + 1) = temp;
}

void	swap_b(t_stack *stack)
{
	int	temp;

	if (stack->cursor - stack->values < 2)
		return ;
	temp = *(stack->cursor - 1);
	*(stack->cursor - 1) = *(stack->cursor - 2);
	*(stack->cursor - 2) = temp;
}

void	swap_ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	push_a(t_stack *stack)
{
	if (stack->cursor == stack->values)// can rewrite if equal :)
		return ;
	stack->cursor++;
}

void	push_b(t_stack *stack)
{
	if (stack->end == stack->cursor)
		return ;
	stack->cursor--;
}

//rotate a 


//rotate b 

//rr

// rrb 

//rra
