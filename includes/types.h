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
	OP_STR_ERR,
	OP_ID_ERR,
	EMPTY_STACK,
} err_t;

typedef enum op_e {
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
} op_enum_t;

typedef struct mem_s {
	void *ptr;
	struct mem_s *next;
} mem_t;

typedef struct stack_s {
	int *data;
	size_t capacity;
	size_t length;
} stack_t;

typedef struct glob_s {
	mem_t		*mem;
	char		*op_str[OP_NUMBER];
	bool_t		(*op_fn[OP_NUMBER])(struct glob_s*);
	bool_t		(*op_rev[OP_NUMBER])(struct glob_s*);
	stack_t		*a;
	stack_t		*b;
} glob_t;

typedef bool_t (*op_fn_t)(glob_t*);

#endif
