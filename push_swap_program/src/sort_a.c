/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:05:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/13 18:21:20 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_a(t_stack *stack, int len)
{
	int	sub_len;
	int	*pivot;
	int	pivot_i;

	if (len <= 1)
		return ;
	if (len == 2)
	{
		if (*(stack->top) > *(stack->top + 1))
		{
			printf("recursion depth done\n");
			swap_a(stack);
			print_array(stack);
		}
		if (stack->top + 1 == stack->end)
			return ;
	}
	sub_len = len / 2;
	pivot = stack->top + sub_len;
	pivot_i = pivot - stack->values;
	printf("new branch sort_a\n");
	printf("len is worth %d\n", len);
	printf("pivot_i is worth %d\n", pivot_i);
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
