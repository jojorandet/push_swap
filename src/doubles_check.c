/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:49:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/30 14:22:01 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack && stack->values && (i < stack->len))
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->values[i] == stack->values[j])
			{
				push_swap_exit(stack, "double found!\n");
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}