

#include "../include/push_swap.h"

void	print_array(t_stack *stack, char *where_i_am)
{
	int	i;

	i = 0;
	DEBUG("%s\n", where_i_am);
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
	print_array(&stack, "array before indexing");
	index_convert(&stack);
	print_array(&stack, "array after indexing");
	sorting(&stack);
	print_array(&stack, "sorted array");
	push_swap_exit(&stack, NULL);
	return (0);
}
