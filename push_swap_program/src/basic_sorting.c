/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:06:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/08 21:39:22 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*int	find_element_position(t_stack *stack, int n)
{
	int	*cursor;
	int	i;

	i = 0;
	cursor = stack->top;
	while (cursor[i] != n && cursor + i <= stack->end)
		i++;
	return (i);
}

void	push_index_to_b(t_stack *stack, int index)
{
	int	i;
	int	n;

	i = find_element_position(stack, index);
	if (i > (stack->len_a / 2))
	{
		n = stack->len_a - i;
		while (n--)
			rev_rot_a(stack);
	}
	else
	{
		while (i--)
			rot_a(stack);
	}
	push_b(stack);
}

void	sort_five_elements(t_stack *stack)
{
	push_index_to_b(stack, 0);
	if (stack->len_a > 3)
		push_index_to_b(stack, 1);
	sort_three_elements(stack);
	push_a(stack);
	if (stack->len_b)
		push_a(stack);
}*/

void	sort_three_elements(t_stack *stack)
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
		swap_a(stack);
	if ((*top > *middle) && (*middle > *bottom) && (*bottom < *top))
	{
		swap_a(stack);
		rev_rot_a(stack);
	}
	if ((*top > *middle) && (*middle < *bottom) && (*bottom > *middle))
		rot_a(stack);
	if ((*top < *middle) && (*middle > *bottom) && (*bottom > *top))
	{
		swap_a(stack);
		rot_a(stack);
	}
	if ((*top < *middle) && (*middle > *bottom) && (*bottom < *top))
		rev_rot_a(stack);
}

void	sort_two_elements(t_stack *stack)
{
	if (stack->values[0] != 0)
		swap_a(stack);
}

void	sorting(t_stack *stack)
{
	if (stack->len == 2)
		sort_two_elements(stack);
	else if (stack->len == 3)
		sort_three_elements(stack);
	/*else if (stack->len <= 5)
		sort_five_elements(stack);*/
	else
		prepare_sort(stack);
	return ;
}