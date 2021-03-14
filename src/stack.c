#include "../includes/includes.h"

stack_t *stack_new(mem_t **mem) {
	stack_t *stack = mem_alloc(mem, sizeof(stack_t));

	stack->length = 0;		
	stack->capacity = 0;
	stack->data = NULL;
	return (stack);
}

stack_t *stack_from_args(mem_t **mem, int argc, char **argv) {
	int		i;
	long	val;
	stack_t *stack = stack_new(mem);
	size_t	j;

	--argc;
	for (i = argc; i > 0; --i) {
		if ((val = my_atoi(argv[i])) == ATOI_ERR_RET)
			error_exit(mem, ATOI_ERR);
		for (j = 0; j < stack->length; ++j) {
			if (stack->data[j] == (int)val) {
				error_exit(mem, DUPLICATES_ERR);
			}
		}
		push_to_stack(mem, stack, (int)val);
	}
	return (stack);
}

void push_to_stack(mem_t **mem, stack_t *stack, int val) {
	int *new_data;
	size_t i;

	if (stack->length + 1 > stack->capacity) {
		stack->capacity = stack->capacity ? stack->capacity * 2 : 1;
		new_data = mem_alloc(mem, stack->capacity * sizeof(int));
		if (stack->data) {
			for (i = 0; i < stack->length; ++i)
				new_data[i] = stack->data[i];
			mem_free_ptr(mem, stack->data, FALSE);
		}
		stack->data = new_data;
	}
	stack->data[stack->length++] = val;
}

int pop_from_stack(mem_t **mem, stack_t *stack) {
	if (!stack->length)
		error_exit(mem, EMPTY_STACK);
	--stack->length;
	return (stack->data[stack->length]);
}

int top_of_stack(mem_t **mem, stack_t *stack) {
	if (!stack->length)
		error_exit(mem, EMPTY_STACK);
	return (stack->data[stack->length - 1]);
}

void stack_free(mem_t **mem, stack_t **stack) {
	if ((*stack)->data) {
		mem_free_ptr(mem, (*stack)->data, FALSE);
	}
	mem_free_ptr(mem, *stack, FALSE);
}

size_t stack_entropy(stack_t *stack) {
	size_t entropy = 0;
	size_t i;

	if (stack->length < 2)
		return (entropy);
	for (i = 0; i < stack->length - 1; ++i) {
		if (stack->data[i] < stack->data[i + 1])
			++entropy;
	}
	return (entropy);
}
