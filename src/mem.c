#include "../includes/includes.h"

mem_t *mem_new(void) {
	mem_t *mem = malloc(sizeof(mem_t));

	if (!mem)
		return (NULL);
	mem->ptr = NULL;
	mem->next = NULL;
	return (mem);
}

static void mem_free(mem_t **mem, mem_t **mem_2_3) {
	mem_t *next;

	if (!mem || !mem_2_3 || !*mem_2_3)
		error_exit(mem, FREE_ERR);
	next = (*mem_2_3)->next;
	free((*mem_2_3)->ptr);
	free(*mem_2_3);
	*mem_2_3 = next;
}

static void rec_mem_free_all(mem_t **mem, mem_t **mem_2_3) {
	if ((*mem_2_3)->next)
		rec_mem_free_all(mem, &(*mem_2_3)->next);
	mem_free(mem, mem_2_3);
}

void mem_free_all(mem_t **mem) {
	if (!mem)
		error_exit(mem, FREE_ALL_ERR);
	if (*mem)
		rec_mem_free_all(mem, mem);
}

void mem_free_ptr(mem_t **mem, void *ptr) {
	mem_t **base = mem;

	if (!mem || !*mem || !ptr)
		error_exit(base, FREE_PTR_ERR_1);
	while (*mem) {
		if ((*mem)->ptr == ptr) {
			mem_free(base, mem);
			return ;
		}
		mem = &(*mem)->next;
	}
	error_exit(base, FREE_PTR_ERR_2);
}

void *mem_alloc(mem_t **mem, size_t size) {
	mem_t *new_ptr = NULL;

	if (!mem)
		error_exit(mem, ALLOC_ERR_1);
	if (!(new_ptr = mem_new()))
		error_exit(mem, ALLOC_ERR_2);
	if (!(new_ptr->ptr = malloc(size)))
		error_exit(mem, ALLOC_ERR_3);
	new_ptr->next = *mem;
	*mem = new_ptr;
	return (new_ptr->ptr);
}

/*
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
