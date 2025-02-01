/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:17:30 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/01 15:07:46 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_exit(t_stack *stack, char *error)
{
	if (stack)
	{
		if (stack->values && stack->top)
		{
			free(stack->top);
			stack->top = NULL;
		}
		free(stack->values);
		stack->values = NULL;
	}
	if (error)
	{
		ft_putstr(error);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
