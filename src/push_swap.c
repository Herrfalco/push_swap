#include "../includes/includes.h"

#define RESULTS_NB 2

int main(int argc, char **argv) {
	glob_t		glob;
	stack_t		*op_stack;
	stack_t		*result[RESULTS_NB] = { 0 };
	size_t		max_rec = 0;
	size_t		i;

	glob_init(&glob, argc, argv);
	op_stack = stack_new(glob.mem);
	while (!result[0]) {
		if (max_rec >= MAX_RECURSION)
			break ;
		back_track(&glob, op_stack, &result[0], max_rec++);
	}
	bubble_sort(&glob, &result[1]);
	for (i = 0; i < RESULTS_NB; ++i) {
		if (result[i])
			print_op_stack(&glob, result[i]);
		else
			write(1, "NULL\n", 5);
		write(1, "\n", 1);
	}
	glob_free(&glob);
	return (0);
}
