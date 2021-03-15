#include "../includes/includes.h"

void	glob_init(glob_t *glob, int argc, char **argv) {
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

	glob->mem = malloc(sizeof(mem_t *));
	*glob->mem = NULL;
	for (i = 0; i < OP_NUMBER; ++i)
		glob->op_str[i] = str_cpy(glob->mem, init_op_str[i]);
	for (i = 0; i < OP_NUMBER; ++i)
		glob->op_fn[i] = init_op_fn[i];
	for (i = 0; i < OP_NUMBER; ++i)
		glob->op_rev[i] = init_op_rev[i];
	glob->a = stack_from_args(glob->mem, argc, argv);
	glob->b = stack_new(glob->mem);
}

glob_t	*glob_cpy(glob_t *glob) {
	glob_t *new_glob = mem_alloc(glob->mem, sizeof(glob_t));
	size_t i;

	new_glob->mem = glob->mem;
	for (i = 0; i < OP_NUMBER; ++i)
		new_glob->op_str[i] = glob->op_str[i];
	for (i = 0; i < OP_NUMBER; ++i)
		new_glob->op_fn[i] = glob->op_fn[i];
	for (i = 0; i < OP_NUMBER; ++i)
		new_glob->op_rev[i] = glob->op_rev[i];
	new_glob->a = stack_cpy(glob->mem, glob->a);
	new_glob->b = stack_cpy(glob->mem, glob->b);
	return (new_glob);
}

void	glob_free_cpy(glob_t **glob) {
	stack_free((*glob)->mem, &(*glob)->a);
	stack_free((*glob)->mem, &(*glob)->b);
	mem_free_ptr((*glob)->mem, *glob);
	*glob = NULL;
}

void	glob_free(glob_t *glob) {
	mem_free_all(glob->mem);
	free(glob->mem);
}
