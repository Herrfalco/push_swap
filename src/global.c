#include "../includes/includes.h"

void	glob_init(glob_t *glob, int argc, char **argv) {
	glob->mem = mem_new();
	char	*init_op_str[] = {
		"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb",
		"rrr",
	};
	op_fn_t	init_op_fn[] = {
		sa,	sb,	ss,	pa,	pb,
		ra,	rb,	rr,	rra, rrb,
		rrr,
	};
	int		init_op_rev[] = {
		SA, SB, SS, PB, PA,
		RRA, RRB, RRR, RA, RB,
		RR,
	};
	size_t	i;

	for (i = 0; i < OP_NUMBER; ++i) {
		glob->op_str[i] = str_cpy(&glob->mem, init_op_str[i]);
	}
	for (i = 0; i < OP_NUMBER; ++i) {
		glob->op_fn[i] = init_op_fn[i];
	}
	for (i = 0; i < OP_NUMBER; ++i) {
		glob->op_rev[i] = init_op_rev[i];
	}
	glob->a = stack_from_args(&glob->mem, argc, argv);
	glob->b = stack_new(&glob->mem);
}

void	glob_free(glob_t *glob) {
	mem_free_all(&glob->mem, TRUE);
}
