#include "../includes/includes.h"

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

static void exec_op(mem_t **mem, stack_t *a, stack_t *b, char *id) {
	int		i = 0;

	for (i = 0; i < OP_NUMBER; ++i) {
		if (!str_cmp(id, op_ids[i])) {
			op_fn[i](mem, a, b);
			return ;
		}
	}
	error_exit(mem, OP_ID_ERR);
}

static void exec_ops(mem_t **mem, stack_t *a, stack_t *b) {
	char	buffer_read[READ_BUFFER_SIZE];
	char	buffer_op[OP_BUFFER_SIZE];
	ssize_t read_ret = 42;
	ssize_t	i;
	size_t	j = 0;

	while (read_ret) {
		if ((read_ret = read(0, buffer_read, READ_BUFFER_SIZE)) < 0)
			error_exit(mem, READ_ERR);
		if (!read_ret) {
			if (j != 0)
				error_exit(mem, OP_LINE_RET_ERR);
			return ;
		}
		for (i = 0; i < read_ret; ++i) {
			if (buffer_read[i] == '\n') {
				buffer_op[j] = '\0';
				exec_op(mem, a, b, buffer_op);
				j = 0;
			} else if (j > 2) {
				error_exit(mem, OP_TOO_LONG);
			} else {
				buffer_op[j++] = buffer_read[i];
			}
		}
	}
}

int main(int argc, char **argv) {
	mem_t *mem;
	stack_t *a;
	stack_t *b;

	if (argc < 2)
		return (0);
	mem = mem_new();
	a = stack_from_args(&mem, argc, argv);
	b = stack_new(&mem);
	print_stack(a, "A");
	print_stack(b, "B");
	exec_ops(&mem, a, b);
	/*
	print_stack(a, "A");
	print_stack(b, "B");
	*/
	write(1, (stack_is_sorted(a) == TRUE && !b->length) ?
		"OK\n" : "KO\n", 3);
	mem_free_all(&mem, TRUE);
	return (0);
}
