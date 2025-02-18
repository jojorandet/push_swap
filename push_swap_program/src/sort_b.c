/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:26:15 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/18 19:36:54 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	restore_rotate(t_stack *stack, t_s *s)
{
	if (s->sub_len < (stack->top - 1) - stack->values)
	{
		while (s->rot_count)
		{
			rev_rot_b(stack);
			s->rot_count--;
		}
	}
}

static  void two_way_sorting(t_stack *stack, t_s *s)
{
    int ops_done;

    ops_done = 0;
    while (s->pushed_count < s->sub_len && ops_done < s->len)
    {
        if (*(stack->top - 1) < s->pivot_index)
        {
            rot_b(stack);
            s->rot_count++;
        }
        else
        {
            push_a(stack);
            s->pushed_count++;
        }
        ops_done++;
    }
    
}

static void sort_initialise(t_stack *stack, t_s *s, int len)
{
    s->len = len;
    s->sub_len = len / 2;
    s->rot_count = 0;
	s->pushed_count = 0;
    s->is_left_touch = (stack->top_i == 0);
	s->is_right_touch = (stack->top_i + s->len == stack->len);
	s->pivot_index = stack->top_i - s->sub_len;
}

void	sort_b(t_stack *stack, int len)
{
	t_s s;

	DEBUG("SORT B\n\n");
	if (len <= 1)
	{
		push_a(stack);
		return ;
	}
	if (len == 2)
	{
		if (*(stack->top - 2) > *(stack->top - 1))
			swap_b(stack);
		push_a(stack);
		push_a(stack);
		return ;
	}
	sort_initialise(stack, &s, len);
	two_way_sorting(stack, &s);
	restore_rotate(stack, &s);
	sort_a(stack, s.sub_len);
	sort_b(stack, s.len - s.sub_len);
}