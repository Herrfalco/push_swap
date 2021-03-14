#include "../includes/includes.h"

void swap(stack_t *stack) {
	int tmp;

	if (stack->length < 2)
		return ;
	tmp = stack->data[stack->length - 1];
	stack->data[stack->length - 1] = stack->data[stack->length - 2];
	stack->data[stack->length - 2] = tmp;
}

void push(mem_t **mem, stack_t *s1, stack_t *s2) {
	if (s1->length < 1)
		return ;
	push_to_stack(mem, s2, pop_from_stack(mem, s1));
}

void rotate(stack_t *stack) {
	int tmp;
	int i = stack->length - 1;

	if (stack->length < 2)
		return ;
	tmp = stack->data[i];
	for (; i > 0; --i)
		stack->data[i] = stack->data[i - 1];
	stack->data[0] = tmp;
}

void rev_rotate(stack_t *stack) {
	int tmp;
	size_t i;

	if (stack->length < 2)
		return ;
	tmp = stack->data[0];
	for (i = 0; i < stack->length - 1; ++i)
		stack->data[i] = stack->data[i + 1];
	stack->data[i] = tmp;
}
