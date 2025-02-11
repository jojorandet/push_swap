/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:23:25 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/11 19:19:12 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../../libft/libft.h"
# include "../../stack/include/stack.h"

typedef struct s_stack t_stack;
//conversion to index 
void	index_convert(t_stack *stack);
//void	sort_five_elements(t_stack *stack);

//swap moves
void	swap_function(int *a, int *b);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);

void	swap_ss(t_stack *stack);

//push moves
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

//rotation moves
void	rot_a(t_stack *stack);
void	rot_b(t_stack *stack);
void	rot_rr(t_stack *stack);

//reverse rotation moves
void	rev_rot_a(t_stack *stack);
void	rev_rot_b(t_stack *stack);
void	rev_rot_rr(t_stack *stack);

//sorting functions
void	sorting(t_stack *stack);
void	sort_two_elements(t_stack *stack);
void	sort_three_elements(t_stack *stack);

//begining of the recursive call
void	sort_stack_a(t_stack *stack);

//big stack sorting
void	prepare_sort(t_stack *stack);

//sorting functions
//void	push_index_to_b(t_stack *stack, t_string *string, int index);
//int		find_element_position(t_stack *stack, int n);

//print the stack
void	print_array(t_stack *stack);

//exit function push swap (calls free stack)
void	push_swap_exit(t_stack *stack, char *error);

#endif