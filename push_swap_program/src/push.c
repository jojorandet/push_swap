/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:13:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/11 22:22:09 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
