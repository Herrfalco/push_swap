#include "../includes/includes.h"

void sa(mem_t **mem, stack_t *a, stack_t *b) {
	swap(a);
}

void sb(mem_t **mem, stack_t *a, stack_t *b) {
	swap(b);
}

void ss(mem_t **mem, stack_t *a, stack_t *b) {
	swap(a);
	swap(b);
}

void pa(mem_t **mem, stack_t *a, stack_t *b) {
	push(mem, b, a);
}

void pb(mem_t **mem, stack_t *a, stack_t *b) {
	push(mem, a, b);
}

void ra(mem_t **mem, stack_t *a, stack_t *b) {
	rotate(a);
}

void rb(mem_t **mem, stack_t *a, stack_t *b) {
	rotate(b);
}

void rr(mem_t **mem, stack_t *a, stack_t *b) {
	rotate(a);
	rotate(b);
}

void rra(mem_t **mem, stack_t *a, stack_t *b) {
	rev_rotate(a);
}

void rrb(mem_t **mem, stack_t *a, stack_t *b) {
	rev_rotate(b);
}

void rrr(mem_t **mem, stack_t *a, stack_t *b) {
	rev_rotate(a);
	rev_rotate(b);
}

const char* op_ids[12] = {
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
    NULL,
};

const opt_t[11];
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

int main(void) {
	return (0);
}
