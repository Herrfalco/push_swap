#include "../includes/includes.h"

bool_t sa(glob_t* glob) {
	return (swap(glob->a));
}

bool_t sb(glob_t* glob) {
	return (swap(glob->b));
}

bool_t ss(glob_t* glob) {
	return (swap(glob->a) == TRUE ? TRUE : swap(glob->b));
}

bool_t pa(glob_t* glob) {
	return (push(glob->mem, glob->b, glob->a));
}

bool_t pb(glob_t* glob) {
	return (push(glob->mem, glob->a, glob->b));
}

bool_t ra(glob_t* glob) {
	return (rotate(glob->a));
}

bool_t rb(glob_t* glob) {
	return (rotate(glob->b));
}

bool_t rr(glob_t* glob) {
	return (rotate(glob->a) == TRUE ? TRUE : rotate(glob->b));
}

bool_t rra(glob_t* glob) {
	return (rev_rotate(glob->a));
}

bool_t rrb(glob_t* glob) {
	return (rev_rotate(glob->b));
}

bool_t rrr(glob_t* glob) {
	return (rev_rotate(glob->a) == TRUE ?
		TRUE : rev_rotate(glob->b));
}
