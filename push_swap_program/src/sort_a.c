/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:35:24 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/15 21:48:18 by jrandet          ###   ########.fr       */
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


void	sort(t_stack *stack, int len, int sub_len)
{
	int	pivot_value;
	int	pushed_count;
	int	ops_done_count;
	int	pivot_i;

	pivot_i = stack->top_i + sub_len;
	pushed_count = 0;
	ops_done_count = 0;
	while ((pushed_count < sub_len) && (ops_done_count < len)) //they both start at 0 this is why i have the strictly smaller
	{
		if (*(stack->top) < pivot_i)
		{
			push_b(stack);
			pushed_count++;
		}
		else
			rot_a(stack);
		ops_done_count++;
	}
	while (ops_done_count > (len - pushed_count))
	{
		rev_rot_a(stack);
		ops_done_count--;
	}
}

void	sort_a(t_stack *stack, int len)
{
	int	sub_len;
	
	
	if (len <= 1)
		return;
	if (len == 2)
	{
		if (*(stack->top) > *(stack->top + 1))
			swap_a(stack);
		return ;
	}
	sub_len = len / 2;
	sort(stack, len, sub_len);
	sort_a(stack, len - sub_len);
	sort_b(stack, len);
}
