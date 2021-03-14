#include "../includes/includes.h"

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
			exec_op_stack(glob, op_stack);
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

int main(int argc, char **argv) {
	glob_t	glob;

	glob_init(&glob, argc, argv);
	if (argc > 1) {
		exec_ops(&glob);
		write(1, (!stack_entropy(glob.a) && !glob.b->length) ?
			"OK\n" : "KO\n", 3);
	}
	glob_free(&glob);
	return (0);
}
