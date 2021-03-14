#include "../includes/includes.h"

static void	insert_op_stack(glob_t *glob, stack_t *op_stack, op_enum_t) {
	push_to
}

/*
static void exec_op(glob_t *glob, char *id) {
	int		i = 0;

	for (i = 0; i < OP_NUMBER; ++i) {
		if (!str_cmp(id, glob->op_str[i])) {
			glob->op_fn[i](glob);
			return ;
		}
	}
	error_exit(&glob->mem, OP_ID_ERR);
}

/*
////
#include <stdio.h>
void print_stack(stack_t *stack, char *mark) {
	size_t i;

	printf("--------%s---------\n", mark);
	printf("capacity:%ld\nlength:%ld\n", stack->capacity, stack->length);
	for (i = 0; i < stack->length; ++i)
		printf("%d\n", stack->data[i]);
	printf("--------top---------\n");
}
/////
*/

int main(int argc, char **argv) {
	glob_t	glob;

	glob_init(&glob, argc, argv);
	if (argc < 2)
		return (0);
	/*
	print_stack(glob->a, "A");
	print_stack(glob->b, "B");
	*/
	exec_ops(&glob);
	/*
	print_stack(a, "A");
	print_stack(b, "B");
	*/
	write(1, (stack_is_sorted(glob.a) == TRUE && !glob.b->length) ?
		"OK\n" : "KO\n", 3);
	glob_free(&glob);
	return (0);
}
