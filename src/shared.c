#include "../includes/includes.h"

bool_t	sorted(glob_t *glob) {
	return (!stack_entropy(glob->a, ASCENDING)
		&& !stack_entropy(glob->b, DESCENDING)
		&& (!glob->a->length || !glob->b->length
			|| top_of_stack(glob->mem, glob->a) > top_of_stack(glob->mem, glob->b)));
}

size_t stack_entropy(stack_t *stack, order_t order) {
	size_t entropy = 0;
	size_t i;

	if (stack->length < 2)
		return (entropy);
	for (i = 0; i < stack->length - 1; ++i) {
		if (order == ASCENDING) {
			if (stack->data[i] < stack->data[i + 1])
				++entropy;
		} else {
			if (stack->data[i] > stack->data[i + 1])
				++entropy;
		}
	}
	return (entropy);
}
