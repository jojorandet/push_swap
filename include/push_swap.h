/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:23:25 by jrandet           #+#    #+#             */
/*   Updated: 2025/01/31 17:13:54 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef	struct s_stack
{
	int *values; //tabkeau d'int
	int	*cursor; //the pointer that allows me to be n between stacks
	int	*end;
	int	len;
}		t_stack;

int		is_int(char *s);
void	check_if_int(int argc, char **argv, t_stack *stack);

void	parse_arguments(int argc, char **argv, t_stack *stack);
void	check_doubles(t_stack *stack);

//swap moves
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
//void	rev_rot_rr(t_stack *stack);

void	push_swap_exit(t_stack *stack, char *error);

#endif