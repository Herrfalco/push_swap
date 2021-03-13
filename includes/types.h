#ifndef TYPES_H
# define TYPES_H

typedef enum boot_e {
	FALSE,
	TRUE,
} bool_t;

typedef enum err_e {
	NO_ERR,
	MEM_INIT,
	ALLOC_ERR_1,
	ALLOC_ERR_2,
	ALLOC_ERR_3,
	FREE_ALL_ERR,
	FREE_PTR_ERR_1,
	FREE_PTR_ERR_2,
	DUPLICATES_ERR,
	ATOI_ERR,
	READ_ERR,
	OP_LINE_RET_ERR,
	OP_TOO_LONG,
	OP_ID_ERR,
} err_t;

typedef struct mem_s {
	void *ptr;
	struct mem_s *next;
} mem_t;

typedef struct stack_s {
	int *data;
	size_t capacity;
	size_t length;
} stack_t;

typedef void (*op_t)(mem_t**, stack_t*, stack_t*);

#endif
