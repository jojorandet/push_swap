/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:40:01 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/19 11:59:09 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->values)
		{
			free(stack->values);
			stack->values = NULL;
		}
	}
}

void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (list[i])
			free(list[i]);
		i++;
	}
	free(list);
}
