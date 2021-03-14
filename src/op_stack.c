#include "../includes/includes.h"

void print_op_stack(glob_t *glob, stack_t *op_stack) {
	size_t	i;
	char	*op_str;

	for (i = 0; i < op_stack->length; ++i) {
		if (op_stack->data[i] < 0 || op_stack->data[i] >= OP_NUMBER)
			error_exit(&glob->mem, OP_ID_ERR);

		op_str = glob->op_str[op_stack->data[i]];
		write(1, op_str, str_len(op_str));
		write(1, "\n", 1);
	}
}

void add_to_op_stack(glob_t *glob, stack_t *op_stack, char *id) {
	size_t	i = 0;

	for (i = 0; i < OP_NUMBER; ++i) {
		if (!str_cmp(id, glob->op_str[i])) {
			push_to_stack(&glob->mem, op_stack, i);
			return ;
		}
	}
	error_exit(&glob->mem, OP_STR_ERR);
}

void exec_op_stack(glob_t *glob, stack_t *op_stack) {
	size_t i = 0;

	for (i = 0; i < op_stack->length; ++i)
		glob->op_fn[op_stack->data[i]](glob);
}
