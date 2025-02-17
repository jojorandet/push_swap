/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:40:08 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/17 20:20:12 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	restore_rotate(t_stack *stack, t_s *s)
{
	if (!s->is_right_touch && !s->is_left_touch)
	{
		while (s->rot_a_count && s->rot_b_count)
		{
			rev_rot_rr(stack);
			s->rot_a_count--;
			s->rot_b_count--;
		}
	}
	if (!s->is_right_touch)
	{
		while (s->rot_a_count)
		{
			rev_rot_a(stack);
			s->rot_a_count--;
		}
	}
	if (!s->is_left_touch)
	{
		while (s->rot_b_count)
		{
			rev_rot_b(stack);
			s->rot_b_count--;
		}
	}
}

static void three_way_sort(t_stack *stack, t_s *s)
{
    while (s->pushed_count < s->sub_len)
    {
		if (*(stack->top - 1) >= s->pivot_one_third)
		{
			push_a(stack);
			if (*(stack->top) < s->pivot_two_thirds)
			{
				rot_a(stack);
				s->rot_a_count++;
			}
			s->pushed_count++;
		}
		else
		{
			rot_b(stack);
			s->rot_b_count++;
		}
   }
}

static void	sort_initialise(t_stack *stack, t_s *s, int len)
{
	s->len = len;
	s->sub_len= (s->len * 2) / 3;
	s->rot_a_count = 0;
	s->rot_b_count = 0;
	s->pushed_count = 0;
	s->is_left_touch = (stack->top_i == 0);
	s->is_right_touch = ((stack->top_i + s->len) == stack->len);
	s->pivot_one_third = stack->top_i - s->sub_len;
	s->pivot_two_thirds = stack->top_i - (s->sub_len / 2);
}

void    sort_b(t_stack *stack, int len)
{
	t_s    s;

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
	three_way_sort(stack, &s);
	restore_rotate(stack, &s);
	sort_a(stack, (s.sub_len));
	sort_b(stack, (s.len - s.sub_len));
}