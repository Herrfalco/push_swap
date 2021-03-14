#include "../includes/includes.h"

/*
///////////
#include <stdio.h>
void print_stacks(glob_t *glob) {
	size_t	max = glob->a->length > glob->b->length ?
		glob->a->length : glob->b->length;
	ssize_t	i;

	printf("-A-B-\n");
	for (i = max - 1; i >= 0; --i) {
		i < (ssize_t)glob->a->length ?
			printf(" %d ", glob->a->data[i]) :
			printf("   ");
		i < (ssize_t)glob->b->length ?
			printf("%d\n", glob->b->data[i]) :
			printf("\n");
	}
	printf("-----\n");
}
//////////
*/

void back_track(glob_t *glob, stack_t *op_stack, stack_t **result, size_t max_rec) {
	size_t	i;

	if (op_stack->length) {
		if (glob->op_fn[top_of_stack(&glob->mem, op_stack)](glob) == FALSE) {
			pop_from_stack(&glob->mem, op_stack);
			return ;
		}
	}
	if (!stack_entropy(glob->a) && !glob->b->length) {
		*result = stack_cpy(&glob->mem, op_stack);
		return ;
	}
	if (op_stack->length <= max_rec) {
		for (i = 0; i < OP_NUMBER; ++i) {
			if (op_stack->length && (top_of_stack(&glob->mem, op_stack) == (int)glob->op_rev[i])) {
				continue ;
			}
			push_to_stack(&glob->mem, op_stack, i);
			back_track(glob, op_stack, result, max_rec);
			if (*result)
				return ;
		}
	}
	if (op_stack->length)
		glob->op_fn[glob->op_rev[pop_from_stack(&glob->mem, op_stack)]](glob);	
}
