/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:41:29 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/21 15:38:33 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../../libft/libft.h"
# include "../../stack/include/stack.h"

typedef struct s_s
{
	int	len;
	int	sub_len;
	int	rot_count;
	int	pushed_count;
	int	is_left_touch;
	int	is_right_touch;
	int	pivot_index;
}				t_s;

typedef struct s_stack	t_stack;

void	index_convert(t_stack *stack);

void	swap_function(int *a, int *b);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);

void	swap_ss(t_stack *stack);

void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

void	rot_a(t_stack *stack);
void	rot_b(t_stack *stack);
void	rot_rr(t_stack *stack);

void	rev_rot_a(t_stack *stack);
void	rev_rot_b(t_stack *stack);
void	rev_rot_rr(t_stack *stack);

void	sorting(t_stack *stack);
void	sort_two_elements(t_stack *stack);
void	sort_three_elements(t_stack *stack);
void	sort_five_elements(t_stack *stack);
void	push_index_to_b(t_stack *stack, int index);
int		find_element_position(t_stack *stack, int n);

void	sort_a(t_stack *stack, int len);
void	sort_b(t_stack *stack, int len);

void	print_array(t_stack *stack, char *where_i_am);

void	push_swap_exit(t_stack *stack, char *error);

#endif