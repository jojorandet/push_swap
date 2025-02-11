/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:27:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/10 13:29:43 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "../../libft/libft.h"
# include "push_swap.h"


typedef struct s_stack
{
	int	*values; //this is my bookshelf that I use to store my values inside
	int	*top; //this is a bookmark pointing to the first value of stack a
	int	*end; //again this is the bookmark pointing to the last value of stack a
	int	len; //the total size of the bookshelf
	int	len_a; //how many books in stack a 
	int	len_b; //how many books in stack b 
}				t_stack;

//free function for the stack
void	free_stack(t_stack *stack);

//validation and parsing function
void	parse_arguments(int argc, char **argv, t_stack *stack);
void	check_if_int(int argc, char **argv, t_stack *stack);
int		is_int(char *s);
void	check_array_len(t_stack *stack, char **array_of_strings);
int		atoll_push_swap(t_stack *stack, const char *str);
void	check_doubles(t_stack *stack);

#endif