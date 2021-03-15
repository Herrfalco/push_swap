#ifndef TYPES_H
# define TYPES_H

typedef enum boot_e {
	FALSE,
	TRUE,
} bool_t;

typedef enum order_e {
	ASCENDING,
	DESCENDING,
} order_t;

typedef enum stack_pos_e {
	TOP,
	SECOND,
	BOTTOM,
	NONE,
} stack_pos_t;

typedef enum err_e {
	NO_ERR,				//	0
	MEM_INIT,			//	1
	ALLOC_ERR_1,		//	2
	ALLOC_ERR_2,		//	3
	ALLOC_ERR_3,		//	4
	FREE_ERR,			//	5
	FREE_ALL_ERR,		//	6
	FREE_PTR_ERR_1,		//	7
	FREE_PTR_ERR_2,		//	8
	FREE_GLOB_CPY,		//	9
	DUPLICATES_ERR,		//	10
	ATOI_ERR,			//	11
	READ_ERR,			//	12
	OP_LINE_RET_ERR,	//	13
	OP_TOO_LONG,		//	14
	OP_STR_ERR,			//	15
	OP_ID_ERR,			//	16
	EMPTY_STACK,		//	17
	NOT_ENOUGH_ELEM,	//	18
} err_t;

typedef enum op_enum_e {
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
	mem_t		**mem;
	char		*op_str[OP_NUMBER];
	bool_t		(*op_fn[OP_NUMBER])(struct glob_s*);
	op_enum_t	op_rev[OP_NUMBER];
	stack_t		*a;
	stack_t		*b;
} glob_t;

typedef bool_t (*op_fn_t)(glob_t*);

typedef struct min_pos_s {
	stack_pos_t		pos;
	int				value;
} min_pos_t;

#endif
