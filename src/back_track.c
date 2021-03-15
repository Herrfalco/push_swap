#include "../includes/includes.h"

static void rec_back_track(glob_t *glob, stack_t *op_stack, stack_t **result, size_t max_rec) {
	size_t	i;

	if (op_stack->length) {
		if (glob->op_fn[top_of_stack(glob->mem,
			op_stack)](glob) == FALSE) {
			pop_from_stack(glob->mem, op_stack);
			return ;
		}
	}
	if (!stack_entropy(glob->a, ASCENDING) &&
		!glob->b->length) {
		*result = stack_cpy(glob->mem, op_stack);
		return ;
	}
	if (op_stack->length <= max_rec) {
		for (i = 0; i < OP_NUMBER; ++i) {
			if (op_stack->length &&
				(top_of_stack(glob->mem, op_stack) ==
				(int)glob->op_rev[i])) {
				continue ;
			}
			push_to_stack(glob->mem, op_stack, i);
			rec_back_track(glob, op_stack, result, max_rec);
			if (*result)
				return ;
		}
	}
	if (op_stack->length)
		glob->op_fn[glob->op_rev[pop_from_stack(glob->mem,
			op_stack)]](glob);	
}

void back_track(glob_t *glob, stack_t **result) {
	stack_t		*op_stack;
	size_t		max_rec = 0;

	op_stack = stack_new(glob->mem);
	while (!*result) {
		if (max_rec >= MAX_RECURSION)
			break ;
		rec_back_track(glob, op_stack, result, max_rec++);
	}
	stack_free(glob->mem, &op_stack);
}
