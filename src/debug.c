#include "../includes/includes.h"

///////////
#include <stdio.h>
void print_stacks(glob_t *glob) {
	size_t	max = glob->a->length > glob->b->length ?
		glob->a->length : glob->b->length;
	ssize_t	i;

	printf("-A-B-\n");
	for (i = max - 1; i >= 0; --i) {
		i < (ssize_t)glob->a->length ?
			printf(" %d ", glob->a->data[i]) :
			printf("   ");
		i < (ssize_t)glob->b->length ?
			printf("%d\n", glob->b->data[i]) :
			printf("\n");
	}
	printf("-----\n");
}

void print_mem(mem_t **mem) {
	printf("---------------------\n");
	while (*mem) {
		printf("%p\n", (*mem)->ptr);
		mem = &(*mem)->next;
	}
	printf("---------------------\n");
}

void print_ptr(void *ptr) {
	printf("---------------------\n");
	printf("%p\n", ptr);
	printf("---------------------\n");
}
//////////
