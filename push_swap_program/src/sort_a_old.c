/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_old.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:05:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/15 18:25:02 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_a_old(t_stack *stack, int len)
{
	int	sub_len;
	int	*pivot;
	int	pivot_i;

	if (len <= 1)
		return ;
	if (len == 2)
	{
		if (*(stack->top) > *(stack->top + 1))
			swap_a(stack);
		DEBUG("recursion depth done\n");
		print_array(stack);
		return ;
	}
	sub_len = len / 2;
	pivot = stack->top + sub_len;
	pivot_i = pivot - stack->values;
	DEBUG("new branch sort_a\n");
	DEBUG("len is worth %d\n", len);
	DEBUG("pivot_i is worth %d\n", pivot_i);
	while (stack->top != pivot)
	{
		if (*(stack->top) >= pivot_i)
			rot_a(stack);
		else
			push_b(stack);
	}
    print_array(stack);
	sort_a(stack, len - sub_len);
	sort_b(stack, sub_len);
	//push_swap_exit(stack, "");
}
