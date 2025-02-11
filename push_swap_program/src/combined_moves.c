/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:52:22 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/11 20:01:15 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rev_rot_rr(t_stack *stack)
{
	rev_rot_a(stack);
	rev_rot_b(stack);
}
