/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:32:49 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/11 20:37:37 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sorting(t_stack *stack)
{
	if (stack->len == 2)
		sort_two_elements(stack);
	else if (stack->len == 3)
		sort_three_elements(stack);
	else if (stack->len <= 5)
		sort_five_elements(stack);
	/*else
		prepare_sort(stack);*/
	return ;
}