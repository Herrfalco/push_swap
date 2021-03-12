#include "../includes/includes.h"

mem_t *mem_new(void) {
	mem_t *mem = malloc(sizeof(mem_t));

	if (!mem)
		return (NULL);
	mem->ptr = NULL;
	mem->next = NULL;
	return (mem);
}

static void mem_free(mem_t **mem, mem_t *repl, bool_t destroy) {
	if ((*mem)->ptr) {
		free((*mem)->ptr);
		(*mem)->ptr = NULL;
	}
	if (destroy) {
		free(*mem);
		*mem = repl;
	}
}

static void rec_mem_free_all(mem_t **mem, bool_t destroy) {
	if ((*mem)->next)
		mem_free_all(&(*mem)->next, TRUE);
	mem_free(mem, NULL, destroy);
}

void mem_free_all(mem_t **mem, bool_t destroy) {
	if (!mem || !*mem)
		error_exit(mem, FREE_ALL_ERR);
	rec_mem_free_all(mem, destroy);
}

void mem_free_ptr(mem_t **mem, void *ptr, bool_t destroy) {
	mem_t **base = mem;

	if (!mem || !*mem || !ptr)
		error_exit(base, FREE_PTR_ERR_1);
	while (*mem) {
		if ((*mem)->ptr == ptr) {
			mem_free(mem, (*mem)->next, !(*base)->next ? destroy : TRUE);
			return ;
		}
		mem = &(*mem)->next;
	}
	error_exit(base, FREE_PTR_ERR_2);
}

void *mem_alloc(mem_t **mem, size_t size) {
	mem_t *new_ptr = NULL;

	if (!mem || !*mem)
		error_exit(mem, ALLOC_ERR_1);
	if ((*mem)->ptr) {
		if (!(new_ptr = mem_new()))
			error_exit(mem, ALLOC_ERR_2);
		new_ptr->next = *mem;
		*mem = new_ptr;
	}
	if (!((*mem)->ptr = malloc(size)))
		error_exit(mem, ALLOC_ERR_3);
	return ((*mem)->ptr);
}

/*
#include <stdio.h>

void print_mem(mem_t **mem) {
	printf("---------------------\n");
	while (*mem) {
		printf("node:%p\n\tptr:%p\n\tnext:%p\n\n", *mem, (*mem)->ptr, (*mem)->next);
		mem = &(*mem)->next;
	}
	printf("---------------------\n");
}

void *failoc(size_t size) {
	static int success_nb = 8;

	if (success_nb) {
		success_nb--;
		return malloc(size);
	}
	return NULL;
}

int main(void) {
	mem_t *mem = mem_new();

	if (!mem) {
		error_exit(NULL, MEM_INIT);
	}

	void *p1 = mem_alloc(&mem, 10);
	void *p2 = mem_alloc(&mem, 10);
	void *p3 = mem_alloc(&mem, 10);
	void *p4 = mem_alloc(&mem, 10);

	print_mem(&mem);

	mem_free_ptr(&mem, p1, TRUE);
	mem_free_ptr(&mem, p3, FALSE);
	mem_free_ptr(&mem, p2, TRUE);
	mem_free_ptr(&mem, p4, FALSE);
	
	print_mem(&mem);

	p1 = mem_alloc(&mem, 10);
	p2 = mem_alloc(&mem, 10);
	p3 = mem_alloc(&mem, 10);
	p4 = mem_alloc(&mem, 10);

	mem_free_all(&mem, FALSE);

	print_mem(&mem);

	p1 = mem_alloc(&mem, 10);
	p2 = mem_alloc(&mem, 10);
	p3 = mem_alloc(&mem, 10);
	p4 = mem_alloc(&mem, 10);

	mem_free_all(&mem, TRUE);

	print_mem(&mem);
}
*/
