#include "../includes/includes.h"

#include <stdio.h>
int main(int argc, char **argv) {
	glob_t		glob;
	stack_t		*result[RESULTS_NB] = { 0 };
	size_t		i;
	size_t		min = 0;
	size_t		min_i = 0;

	glob_init(&glob, argc, argv);
	bubble_sort(&glob, &result[0]);
	insertion_sort(&glob, &result[1]);
	back_track(&glob, &result[2]);
	min = result[0]->length;
	min_i = 0;
	for (i = 1; i < RESULTS_NB; ++i) {
		if (result[i] && result[i]->length < min) {
			min = result[i]->length;
			min_i = i;
		}
	}
	print_op_stack(&glob, result[min_i]);
	glob_free(&glob);
	return (0);
}
