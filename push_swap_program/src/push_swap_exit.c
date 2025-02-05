/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:17:30 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/05 13:18:37 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap_exit(t_stack *stack, char *error)
{

	free_stack(stack);
	if (error)
	{
		ft_putstr(error);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
