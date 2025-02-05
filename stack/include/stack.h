/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:27:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/05 13:13:36 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../libft/libft.h"
# include "push_swap.h"


typedef struct s_stack
{
	int	*values; //tabkeau d'int
	int	*top; //the pointer that allows me to be n between stacks
	int	*end;
	int	len;
}				t_stack;

//free function for the stack
void	free_stack(t_stack *stack);

//validation and parsing function
void	parse_arguments(int argc, char **argv, t_stack *stack);
void	check_if_int(int argc, char **argv, t_stack *stack);
int		is_int(char *s);
void	check_doubles(t_stack *stack);

#endif