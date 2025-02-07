/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:23:25 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/07 12:38:03 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "string_utils.h"
# include "../../libft/libft.h"
# include "stack.h"

typedef struct s_stack t_stack;
//conversion to index 
void	index_convert(t_stack *stack);
//void	sort_five_elements(t_stack *stack);

//swap moves
void	swap_function(int *a, int *b);
void	swap_a(t_stack *stack, t_string *string);
void	swap_b(t_stack *stack, t_string *string);

void	swap_ss(t_stack *stack, t_string *string);

//push moves
void	push_a(t_stack *stack, t_string *string);
void	push_b(t_stack *stack, t_string *string);

//rotation moves
void	rot_a(t_stack *stack, t_string *string);
void	rot_b(t_stack *stack, t_string *string);
void	rot_rr(t_stack *stack, t_string *string);

//reverse rotation moves
void	rev_rot_a(t_stack *stack, t_string *string);
void	rev_rot_b(t_stack *stack, t_string *string);
void	rev_rot_rr(t_stack *stack, t_string *string);

//sorting functions
void	sorting(t_stack *stack, t_string *string);
void	sort_two_elements(t_stack *stack, t_string *string);
void	sort_three_elements(t_stack *stack, t_string *string);

//big stack sorting
void	prepare_sort(t_stack *stack, t_string *string);

//sorting functions
int		find_median(t_stack *stack);

//srtring concat functions 
void	init_string(t_string *string);
void	free_string(t_string *string);

//print the stack
void	print_array(t_stack *stack);

//exit function push swap (calls free stack)
void	push_swap_exit(t_stack *stack, char *error);

#endif