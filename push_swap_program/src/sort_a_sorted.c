/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:45:53 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/18 18:53:00 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



static void sort_initialise(t_stack *stack, t_s *s, int len)
{
    s->len = len;
    s->sub_len = len / 2;
    s->rot_a_count = 0;
    s->rot_b_count = 0;
    s->is_left_touch
}

void	sort_a(t_stack *stack, int len)
{
    t_s         s;
	
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
    sort_initialise(stack, &s, len);
	two_way_sorting(stack, &s);
    restore_rotate(&s);
	sort_a(stack, s.len - s.sub_len);
	sort_b(stack, s.sub_len);
}