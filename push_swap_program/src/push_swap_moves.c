/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:13:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/08 21:43:50 by jrandet          ###   ########.fr       */
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

void	swap_a(t_stack *stack)
{
	if (stack->end - stack->top < 1)
		return ;
	swap_function(stack->top, (stack->top + 1));
	printf("sa\n");
}

void	swap_b(t_stack *stack)
{
	if (stack->top - stack->values < 2)
		return ;
	swap_function((stack->top - 1), (stack->top - 2));
	printf("sb\n");
}

void	push_a(t_stack *stack)
{
	if (stack->top == stack->values)
		return ;
	stack->top--;
	stack->len_a++;
	stack->len_b--;
	printf("pa\n");
}

void	push_b(t_stack *stack)
{
	if (stack->end == (stack->top - 1))
		return ;
	stack->top++;
	stack->len_a--;
	stack->len_b++;
	printf("pb\n");
}
