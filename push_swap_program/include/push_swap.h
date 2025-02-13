/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:30:49 by yourlogin         #+#    #+#             */
/*   Updated: 2025/02/12 15:30:49 by yourlogin        ###   ########.ch       */
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

# define DEBUG_ENABLE 0
# define DEBUG(...) if (DEBUG_ENABLE) printf(__VA_ARGS__);

typedef struct s_stack t_stack;
//conversion to index 
void	index_convert(t_stack *stack);

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
void	sort_five_elements(t_stack *stack);
void	push_index_to_b(t_stack *stack, int index);
int		find_element_position(t_stack *stack, int n);

//begining of the recursive call
void    sort_a(t_stack *stack, int len);
void	sort_b(t_stack *stack, int len);

//print the stack
void	print_array(t_stack *stack);

//exit function push swap (calls free stack)
void	push_swap_exit(t_stack *stack, char *error);

#endif