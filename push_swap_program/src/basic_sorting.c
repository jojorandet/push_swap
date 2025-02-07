/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:06:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/07 19:10:39 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_smaller_index(t_stack *stack, int n)
{
	int	*cursor;
	int	i;

	i = 0;
	cursor = stack->top;
	while (cursor[i] != n && cursor + i <= stack->end)
		i++;
	return (i);
}

void	push_index_to_b(t_stack *stack, t_string *string, int index)
{
	int	i;
	int	n;

	i = check_smaller_index(stack, index);
	if (i > (stack->len_a / 2))
	{
		n = stack->len_a - i;
		while (n--)
			rev_rot_a(stack, string);
	}
	else
	{
		while (i--)
			rot_a(stack, string);
	}
	push_b(stack, string);
}

void	sort_five_elements(t_stack *stack, t_string *string)
{
	push_index_to_b(stack, string, 0);
	if (stack->len_a > 3)
		push_index_to_b(stack, string, 1);
	sort_three_elements(stack, string);
	push_a(stack, string);
	if (stack->len_b)
		push_a(stack, string);
}

void	sort_three_elements(t_stack *stack, t_string *string)
{
	int	*top;
	int	*middle;
	int	*bottom;

	top = stack->top;
	middle = top + 1;
	bottom = stack->end;
	if ((*top < *middle) && (*middle < *bottom))
		return ;
	if ((*top < *middle) && (*middle > *bottom) && (*top > *bottom))
		swap_a(stack, string);
	if ((*top > *middle) && (*middle > *bottom) && (*bottom < *top))
	{
		swap_a(stack, string);
		rev_rot_a(stack, string);
	}
	if ((*top > *middle) && (*middle < *bottom) && (*bottom > *middle))
		rot_a(stack, string);
	if ((*top < *middle) && (*middle > *bottom) && (*bottom > *top))
	{
		swap_a(stack, string);
		rot_a(stack, string);
	}
	if ((*top < *middle) && (*middle > *bottom) && (*bottom < *top))
		rev_rot_a(stack, string);
}

void	sort_two_elements(t_stack *stack, t_string *string)
{
	int i;
	
	i = 0;
	if (stack->values[i] > stack->values[i + 1])
		swap_a(stack, string);
}

void	sorting(t_stack *stack, t_string *string)
{
	if (stack->len == 2)
		sort_two_elements(stack, string);
	else if (stack->len == 3)
		sort_three_elements(stack, string);
	else if (stack->len <= 5)
		sort_five_elements(stack, string);
	else
		prepare_sort(stack, string);
	return ;
}