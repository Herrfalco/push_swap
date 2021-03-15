#include "../includes/includes.h"

static bool_t	sorted(glob_t *glob) {
	return (!stack_entropy(glob->a, ASCENDING)
		&& !stack_entropy(glob->b, DESCENDING)
		&& (!glob->a->length || !glob->b->length
			|| top_of_stack(glob->mem, glob->a) > top_of_stack(glob->mem, glob->b)));
}

void	bubble_sort(glob_t *glob_base, stack_t **result) {
	glob_t	*glob = glob_cpy(glob_base);
	stack_t *cur_stack = glob->a;
	size_t	remainder = 1;
	*result = stack_new(glob->mem);

	while (!sorted(glob)) {
		if (cur_stack->length == remainder) {
			if (cur_stack == glob->b)
				++remainder;
			cur_stack = cur_stack == glob->a
				? glob->b : glob->a;
		}
		if (cur_stack == glob->a) {
			if (top_of_stack(glob->mem, glob->a) >
				sec_of_stack(glob->mem, glob->a)) {
				push_to_stack(glob->mem, *result, SA);
				sa(glob);
			} else {
				push_to_stack(glob->mem, *result, PB);
				pb(glob);
			}
		} else {
			if (top_of_stack(glob->mem, glob->b) <
				sec_of_stack(glob->mem, glob->b)) {
				push_to_stack(glob->mem, *result, SB);
				sb(glob);
			} else {
				push_to_stack(glob->mem, *result, PA);
				pa(glob);
			}
		}
	}
	while (glob->b->length) {
		push_to_stack(glob->mem, *result, PA);
		pa(glob);
	}
	glob_free_cpy(&glob);
}
