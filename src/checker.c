#include "headers.h"

typedef enum inst_e {
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
} inst_t;

typedef enum data_e {
	STACK,
	INST,
} data_t;

typedef struct vec {
	void **data;
	data_t type;
	size_t capacity;	
	size_t length;
} vec_t;

vec_t *vec_new_cap(data_t type, size_t cap) {
	vec_t *vec = NULL;

	if (!(vec = malloc(sizeof(vec_t))) ||
		!(vec->data = malloc(sizeof(void *) * cap))) {
		exit_error(ALLOC);
	}
	vec->type = type;
	vec->capacity = cap;
	vec->length = 0;
	return (vec);
}

void vec_free(vec_t *vec) {
	free(vec->data);
	free(vec);
}

int main(int argc, char **argv) {
	vec_t	*vec = vec_new_cap(STACK, 10);

	(void)argc;
	(void)argv;
	(void)vec;
	return (0);
}
