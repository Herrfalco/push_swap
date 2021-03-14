#include "../includes/includes.h"

static void add_to_op_stack(glob_t *glob, stack_t *op_stack, char *id) {
	int		i = 0;

	for (i = 0; i < OP_NUMBER; ++i) {
		if (!str_cmp(id, glob->op_str[i])) {
			push_to_stack(&glob->mem, op_stack, i);
			return ;
		}
	}
	error_exit(&glob->mem, OP_STR_ERR);
}

static void exec_ops(glob_t *glob) {
	stack_t *op_stack = stack_new(&glob->mem);
	char	buffer_read[READ_BUFFER_SIZE];
	char	buffer_op[OP_BUFFER_SIZE];
	ssize_t read_ret = 42;
	ssize_t	i;
	size_t	j = 0;

	while (read_ret) {
		if ((read_ret = read(0, buffer_read, READ_BUFFER_SIZE)) < 0)
			error_exit(&glob->mem, READ_ERR);
		if (!read_ret) {
			if (j != 0)
				error_exit(&glob->mem, OP_LINE_RET_ERR);
			for (i = 0; i < OP_NUMBER; ++i)
				glob->op_fn[i](glob);
			return ;
		}
		for (i = 0; i < read_ret; ++i) {
			if (buffer_read[i] == '\n') {
				buffer_op[j] = '\0';
				add_to_op_stack(glob, op_stack, buffer_op);
				j = 0;
			} else if (j > 2) {
				error_exit(&glob->mem, OP_TOO_LONG);
			} else {
				buffer_op[j++] = buffer_read[i];
			}
		}
	}
}

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

int main(int argc, char **argv) {
	glob_t	glob;

	glob_init(&glob, argc, argv);
	if (argc < 2)
		return (0);
	print_stack(glob.a, "A");
	print_stack(glob.b, "B");
	exec_ops(&glob);
	print_stack(glob.a, "A");
	print_stack(glob.b, "B");
	write(1, (!stack_entropy(glob.a) && !glob.b->length) ?
		"OK\n" : "KO\n", 3);
	glob_free(&glob);
	return (0);
}
