/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:20:46 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/01 15:21:13 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	tester_moves()
	print_array(&stack);
	swap_a(&stack);
	printf("swap a\n\n");
	print_array(&stack);
	push_b(&stack);
	printf("push b\n\n");
	print_array(&stack);
	rot_a(&stack);
	printf("rot a\n\n");
	print_array(&stack);
	rot_b(&stack);
	printf("rot b\n\n");
	print_array(&stack);
	rev_rot_a(&stack);
	printf("rev_rot a\n\n");
	print_array(&stack);
	push_b(&stack);
	print_array(&stack);
	push_b(&stack);
	print_array(&stack);
	rev_rot_b(&stack);
	printf("rev_rot b\n\n");
	print_array(&stack);
	return (0);