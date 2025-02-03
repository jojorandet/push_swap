/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:52:22 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/03 17:34:09 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ss(t_stack *stack, t_string *string)
{
	swap_a(stack, string);
	swap_b(stack, string);
}

void	rot_rr(t_stack *stack, t_string *string)
{
	rot_a(stack, string);
	rot_b(stack, string);
}

void	rev_rot_rr(t_stack *stack, t_string *string)
{
	rev_rot_a(stack, string);
	rev_rot_b(stack, string);
}
