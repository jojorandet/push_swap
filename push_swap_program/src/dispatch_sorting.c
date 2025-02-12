/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:44:38 by yourlogin         #+#    #+#             */
/*   Updated: 2025/02/12 15:19:34 by yourlogin        ###   ########.ch       */
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
	else
		sort_a(stack, stack->len);
	return ;
}