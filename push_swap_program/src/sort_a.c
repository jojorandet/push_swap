/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:33:35 by yourlogin         #+#    #+#             */
/*   Updated: 2025/02/12 18:05:14 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int     is_between(int x, int min, int max)
{
    return (min <= x && x <= max);
}

void    push_and_pull_pivot(t_stack *stack, int pivot, int len)
{
    int min;
    int max;
    int count;

    min = stack->top;
    max = 
    while ((stack->top) < pivot)
    {
        while (is_between(*(stack->top), min, max))
        {
            if (*(stack->top))
        }
    }

}

void    sort_a(t_stack *stack, int len)
{
    int sub_len;
    int pivot;

    printf("the value of sack->len is %d, and len is %d\n", stack->len, len);
    printf("the value pointed at the begining is %d\n", *(stack->top));
    sub_len = len / 2;
    printf("len is %d, and sub_len is %d\n", len, sub_len);
    pivot = 
    
    

    //I have the top pointer 
    //wiht the top pointer, I will add the cursor until i am at the end 
    // here right now I am onlz dealing with stack a 
    // top val val val end
    //top is the pointer that will move forw or backward. 
   // if (len == 2)
    // {
    //     if (stack->top > stack->end)
    //         swap_a(stack);
    // }
    //print_array(stack);
    //sort_a(stack, sub_len);
    //sort_b
    push_swap_exit(stack, "temp exit :)\n");
    
    printf("the value pointed by pivot is %d\n", *pivot);
}
