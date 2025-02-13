

#include "../include/push_swap.h"

void	print_array(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (&stack->values[i] == stack->top)
			printf(" | ");
		printf(" %d ", stack->values[i]);
		i++;
	}
	printf("\n\n");
}

int	main(int argc, char **argv)
{
	t_stack		stack;

	parse_arguments(argc, argv, &stack);
	printf("original array:\n");
	print_array(&stack);
	index_convert(&stack);
	printf("indexed array:\n");
	print_array(&stack);
	sorting(&stack);
	printf("sorted array\n");
	print_array(&stack);
	push_swap_exit(&stack, "exited program");
	return (0);
}
