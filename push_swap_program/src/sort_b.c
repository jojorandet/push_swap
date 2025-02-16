/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:57:05 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/16 20:25:43 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// /0 4 3 5 2 1 pivot = 5
// /4 3 5 2 1 0 p = 0 o = 1
// /3 5 2 1 0 4 p = 0 o = 2
// /5 2 1 0 4 3 p = 0 o = 3
// 5 / 2 1 0 4 3 p = 1 o = 4
// 5 / 1 0 4 3 2 p = 1 o = 5
// 5 / 0 4 3 2 1 p = 1 o = 6    len - pushed count 6 - 1 = 5  op = 6 

// 5 / 1 0 4 3 2 rev rot a

// 0 4 3 5 2 1 pivot = 3
// 0 /4 3 5 2 1 p = 1 o = 1
// 0/ 3 5 2 1 4 p = 1 o = 2
// 0 /5 2 1 4 3 p = 1 o = 3
// 0 /2 1 4 3 5 p = 1 o = 4
// 0 2 /1 4 3 5 p = 2 o = 5
// 0 2 1/ 4 3 5 p = 3 o = 6 

//sort a
// 0 2 1 /4 3 5 piv = 4
// 0 2 1 / 3 5 4 p =n 0 o = 1
// 0 2 1 3 / 5 4 len == 2

//sort a 
// 0 2 1 3/ 4 5 swap a

static void main_sorting_b(t_stack *stack, int len, int sub_len)
{
	int	pivot_i;
	int	pushed_count;
	int	rot_count;
	int	ops_done_count;

	pivot_i = (stack->top_i) - sub_len;
	DEBUG("top_i is worth %d\n", stack->top_i);
	DEBUG("len is worth %d\n", len);
	DEBUG("sub_len is worth %d\n", sub_len);
	DEBUG("pivot_i is worth %d\n", pivot_i);
	pushed_count = 0;
	ops_done_count = 0;
	rot_count = 0;
	while ((pushed_count < sub_len) && (ops_done_count < len))
	{
		if (*(stack->top - 1) < pivot_i)
		{
			rot_b(stack);
			print_array(stack, "top - 1 < pivot i, rotb");
			rot_count++;
		}
		else
		{
			push_a(stack);
			print_array(stack, "top - 1 >= pivot, pushb");
			pushed_count++;
		}
		ops_done_count++;
		DEBUG("pushed = %d, op_d = %d\n\n", pushed_count, ops_done_count);
	}
	if (sub_len < ((stack->top - 1) - stack->values))
	{
		while (rot_count)
		{
			rev_rot_b(stack);
			print_array(stack, "roll back rev rotate b");
			rot_count--;
		}
		print_array(stack, "stack after main_sorting_b");
	}
}

void	sort_b(t_stack *stack, int len)
{
	int	sub_len;

	DEBUG("SORT B\n\n");
	if (len <= 1)
	{
		push_a(stack);
		return ;
	}
	if (len == 2)
	{
		if (*(stack->top - 2) > *(stack->top - 1))
		{
			swap_b(stack);
			print_array(stack, "in sort_b, len == 2, swap b");
		}
		push_a(stack);
		push_a(stack);
		print_array(stack, "sort b len == 2 done");
		return ;
	}
	sub_len = len / 2;
	main_sorting_b(stack, len, sub_len);
	sort_a(stack, sub_len);
	sort_b(stack, len - sub_len);
}