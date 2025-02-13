/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:06:08 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/13 22:20:53 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_b(t_stack *stack, int len)
{
	int	sub_len;
	int	*pivot;
	int	pivot_i;

	if (len <= 1)
		return ;
	if (len == 2)
	{
		if (*(stack->top - 2) > *(stack->top - 1))
			swap_b(stack);
		push_a(stack);
		push_a(stack);
		return ;
	}
	sub_len = len / 2;
	pivot = stack->top - sub_len;
	pivot_i = pivot - stack->values;
	DEBUG("branch swap_b\n")
	DEBUG("len is worth %d\n", len)
	DEBUG("pivot_i is worth %d\n", pivot_i)
	DEBUG("stack->top is worth %d\n", *(stack->top))
	while (stack->top != pivot)
	{
		if (*(stack->top - 1) >= pivot_i)
			push_a(stack);
		else
			rot_b(stack);
	}
	print_array(stack);
	sort_b(stack, (len - sub_len));
	sort_a(stack, sub_len);
	//push_swap_exit(stack, " ");
}
