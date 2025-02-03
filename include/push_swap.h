/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:23:25 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/03 17:35:01 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "string_utils.h"

typedef struct s_stack
{
	int	*values; //tabkeau d'int
	int	*top; //the pointer that allows me to be n between stacks
	int	*end;
	int	len;
}				t_stack;

//parsing of the arguments
int		is_int(char *s);
void	check_if_int(int argc, char **argv, t_stack *stack);
void	parse_arguments(int argc, char **argv, t_stack *stack);
void	check_doubles(t_stack *stack);

//conversion to index 
void	index_convert(t_stack *stack);

//sorting functions
void	sorting(t_stack *stack, t_string *string);
void	sort_two_elements(t_stack *stack, t_string *string);
void	sort_three_elements(t_stack *stack, t_string *string);
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


void	push_swap_exit(t_stack *stack, char *error);

#endif