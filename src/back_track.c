#include "../includes/includes.h"

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
	if (op_stack->length < max_rec) {
		for (i = 0; i < OP_NUMBER; ++i) {
			push_to_stack(&glob->mem, op_stack, i);
			back_track(glob, op_stack, result, max_rec);
			if (*result)
				return ;
		}
	}
	if (op_stack->length)
		glob->op_rev[pop_from_stack(&glob->mem, op_stack)](glob);	
}

int main(int argc, char **argv) {
	glob_t		glob;
	stack_t		*op_stack;
	stack_t		*result = NULL;
	size_t		max_rec = 0;

	glob_init(&glob, argc, argv);
	op_stack = stack_new(&glob.mem);
	while (!result) {
		if (max_rec >= MAX_RECURSION) {
			write(1, "too much recursion", 18);
			break ;
		}
		back_track(&glob, op_stack, &result, max_rec++);
		if (result) {
			print_op_stack(&glob, result);
			break ;
		}
	}
	glob_free(&glob);
	return (0);
}
