/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:54:05 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/11 20:01:47 by jrandet          ###   ########.fr       */
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

void	swap_ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
