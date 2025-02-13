

#include "../include/push_swap.h"

void	print_array(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (&stack->values[i] == stack->top)
		{
			DEBUG("|")
		}
		else
		{
			DEBUG(" ")
		}
		DEBUG(" %d ", stack->values[i])
		i++;
	}
	DEBUG("\n\n");
}

int	main(int argc, char **argv)
{
	t_stack		stack;

	parse_arguments(argc, argv, &stack);
	DEBUG("original array:\n");
	print_array(&stack);
	index_convert(&stack);
	DEBUG("indexed array:\n");
	print_array(&stack);
	sorting(&stack);
	DEBUG("sorted array\n");
	print_array(&stack);
	push_swap_exit(&stack, NULL);
	return (0);
}
