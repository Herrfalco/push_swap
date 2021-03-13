#include "../includes/includes.h"

static void sa(mem_t **mem, stack_t *a, stack_t *b) {
	(void)mem;
	(void)b;
	swap(a);
}

static void sb(mem_t **mem, stack_t *a, stack_t *b) {
	(void)mem;
	(void)a;
	swap(b);
}

static void ss(mem_t **mem, stack_t *a, stack_t *b) {
	(void)mem;
	swap(a);
	swap(b);
}

static void pa(mem_t **mem, stack_t *a, stack_t *b) {
	push(mem, b, a);
}

static void pb(mem_t **mem, stack_t *a, stack_t *b) {
	push(mem, a, b);
}

static void ra(mem_t **mem, stack_t *a, stack_t *b) {
	(void)mem;
	(void)b;
	rotate(a);
}

static void rb(mem_t **mem, stack_t *a, stack_t *b) {
	(void)mem;
	(void)a;
	rotate(b);
}

static void rr(mem_t **mem, stack_t *a, stack_t *b) {
	(void)mem;
	rotate(a);
	rotate(b);
}

static void rra(mem_t **mem, stack_t *a, stack_t *b) {
	(void)mem;
	(void)b;
	rev_rotate(a);
}

static void rrb(mem_t **mem, stack_t *a, stack_t *b) {
	(void)mem;
	(void)a;
	rev_rotate(b);
}

static void rrr(mem_t **mem, stack_t *a, stack_t *b) {
	(void)mem;
	rev_rotate(a);
	rev_rotate(b);
}

const char* op_ids[] = {
    "sa",
    "sb",
    "ss",
    "pa",
    "pb",
    "ra",
    "rb",
    "rr",
    "rra",
    "rrb",
    "rrr",
};

const op_t op_fn[] = {
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
};
