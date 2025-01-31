/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:52:22 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/31 18:55:00 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	rot_rr(t_stack *stack)
{
	rot_a(stack);
	rot_b(stack);
}

void	rev_rot_rr(t_stack *stack)
{
	rev_rot_a(stack);
	//rev_rot_b(stack);
}