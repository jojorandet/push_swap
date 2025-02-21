/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:44:01 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/21 14:47:04 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack;

	parse_arguments(argc, argv, &stack);
	index_convert(&stack);
	sorting(&stack);
	push_swap_exit(&stack, NULL);
	return (0);
}
