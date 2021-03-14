#include "../includes/includes.h"

void back_track(glob_t *glob, stack_t *op_stack, size_t *recursion) {
	size_t	i;

	glob->op_fn[top_of_stack(&glob->mem, op_stack)](glob);
	if (!stack_entropy(glob->a) && !glob->b->length) {
		write(1, "vvvvvvvvvv\n", 11);
		print_op_stack(glob, op_stack);
	} else if (*recursion < MAX_RECURSION) {
		for (i = 0; i < OP_NUMBER; ++i) {
			push_to_stack(&glob->mem, op_stack, i);
			++(*recursion);
			back_track(glob, op_stack, recursion);
		}
	}
	--(*recursion);
	glob->op_rev[pop_from_stack(&glob->mem, op_stack)](glob);	
}

int main(int argc, char **argv) {
	glob_t		glob;
	stack_t		*op_stack;
	size_t		recursion = 0;

	glob_init(&glob, argc, argv);
	op_stack = stack_new(&glob.mem);
	back_track(&glob, op_stack, &recursion);
	glob_free(&glob);
	return (0);
}
