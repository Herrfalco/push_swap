#include "../includes/includes.h"

static min_pos_t	stack_min_pos(mem_t **mem, stack_t *stack) {
	min_pos_t		min = { NONE, 0 };
	int				tmp;

	if (!stack->length)
		return min;
	min.value = top_of_stack(mem, stack);
	min.pos = TOP;
	if (stack->length > 1 &&
		(tmp = bot_of_stack(mem, stack)) < min.value) {
			min.value = tmp;
			min.pos = BOTTOM;
	}
	if (stack->length > 2 &&
		(tmp = sec_of_stack(mem, stack)) < min.value) {
			min.value = tmp;
			min.pos = SECOND;
	}
	return (min);
}

void	insertion_sort(glob_t *glob_base, stack_t **result) {
	glob_t	*glob = glob_cpy(glob_base);
	min_pos_t		min;
	*result = stack_new(glob->mem);

	while (!sorted(glob)) {
		min = stack_min_pos(glob->mem, glob->a);
		if (min.pos == BOTTOM) {
			push_to_stack(glob->mem, *result, RRA);
			rra(glob);
		} else if (min.pos == SECOND) {
			push_to_stack(glob->mem, *result, SA);
			sa(glob);
		}
		if (sorted(glob))
			break ;
		if (!glob->b->length || min.value >
			top_of_stack(glob->mem, glob->b)) {
			push_to_stack(glob->mem, *result, PB);
			pb(glob);
		} else if (min.value <
			bot_of_stack(glob->mem, glob->b)) {
			push_to_stack(glob->mem, *result, PB);
			push_to_stack(glob->mem, *result, RB);
			pb(glob);
			rb(glob);
		} else {
			push_to_stack(glob->mem, *result, RA);
			ra(glob);
			while (glob->b->length &&
				top_of_stack(glob->mem, glob->b) >
				min.value) {
				push_to_stack(glob->mem, *result, PA);
				pa(glob);
			}
			push_to_stack(glob->mem, *result, RRA);
			rra(glob);
		}
	}
	while (glob->b->length) {
		push_to_stack(glob->mem, *result, PA);
		pa(glob);
	}
	glob_free_cpy(&glob);
}
