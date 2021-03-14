#include "../includes/includes.h"

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
