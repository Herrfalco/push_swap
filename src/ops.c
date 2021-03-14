#include "../includes/includes.h"

void sa(glob_t* glob) {
	swap(glob->a);
}

void sb(glob_t* glob) {
	swap(glob->b);
}

void ss(glob_t* glob) {
	swap(glob->a);
	swap(glob->b);
}

void pa(glob_t* glob) {
	push(&glob->mem, glob->b, glob->a);
}

void pb(glob_t* glob) {
	push(&glob->mem, glob->a, glob->b);
}

void ra(glob_t* glob) {
	rotate(glob->a);
}

void rb(glob_t* glob) {
	rotate(glob->b);
}

void rr(glob_t* glob) {
	rotate(glob->a);
	rotate(glob->b);
}

void rra(glob_t* glob) {
	rev_rotate(glob->a);
}

void rrb(glob_t* glob) {
	rev_rotate(glob->b);
}

void rrr(glob_t* glob) {
	rev_rotate(glob->a);
	rev_rotate(glob->b);
}
