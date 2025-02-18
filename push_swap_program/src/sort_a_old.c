/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_old.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:35:24 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/18 19:33:35 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	main_sorting_a(t_stack *stack, int len, int sub_len)
{
	int	pivot_i;
	int	pushed_count;
	int	rot_count;
	int	ops_done_count;

	pivot_i = stack->top_i + sub_len;
	DEBUG("\n\ntop_i is worth %d\n", stack->top_i);
	DEBUG("len is worth %d\n", len);
	DEBUG("sub_len is worth %d\n", sub_len);
	DEBUG("pivot_i is worth %d\n\n", pivot_i);
	pushed_count = 0;
	ops_done_count = 0;
	rot_count = 0;
	while ((pushed_count < sub_len) && (ops_done_count < len)) //they both start at 0 this is why i have the strictly smaller
	{
		if (*(stack->top) < pivot_i)
		{
			push_b(stack);
			print_array(stack, "top < pivot i, push_b");
			pushed_count++;
		}
		else
		{
			rot_a(stack);
			print_array(stack, "top >= pivot i, rota");
			rot_count++;
		}
		ops_done_count++;
		DEBUG("pushed = %d, op_d = %d\n\n", pushed_count, ops_done_count);
	}
	if (sub_len < (stack->end - stack->top))
	{
		while (rot_count)
		{
			rev_rot_a(stack);
			print_array(stack, "roll back rev rotate a");
			rot_count--;
		}
		print_array(stack, "stack after main_sorting_a");
	}
}

void	sort_a_old(t_stack *stack, int len)
{
	int	sub_len;
	
	DEBUG("SORT A\n\n");
	if (len <= 1)
	{
		return;
	}
	if (len == 2)
	{
		if (*(stack->top) > *(stack->top + 1))
		{
			swap_a(stack);
			print_array(stack, "sort a len == 2, swap a");
		}
		print_array(stack, "sort a len == 2 done");
		return ;
	}
	sub_len = len / 2;
	main_sorting_a(stack, len, sub_len);
	sort_a(stack, len - sub_len);
	sort_b(stack, sub_len);
}
