/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:44 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 21:28:07 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum	e_bool {
	FALSE,
	TRUE,
}				t_bool;

typedef enum	e_order {
	ASCENDING,
	DESCENDING,
}				t_order;

typedef enum	e_stack_pos {
	TOP,
	SECOND,
	BOTTOM,
	NONE,
}				t_stack_pos;

typedef enum	e_err {
	NO_ERR,
	MEM_INIT,
	ALLOC_ERR_1,
	ALLOC_ERR_2,
	ALLOC_ERR_3,
	FREE_ERR,
	FREE_ALL_ERR,
	FREE_PTR_ERR_1,
	FREE_PTR_ERR_2,
	FREE_GLOB_CPY,
	DUPLICATES_ERR,
	ATOI_ERR,
	READ_ERR,
	OP_LINE_RET_ERR,
	OP_TOO_LONG,
	OP_STR_ERR,
	OP_ID_ERR,
	EMPTY_STACK,
	NOT_ENOUGH_ELEM,
}				t_err;

typedef enum	e_op_enum {
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
}				t_op_enum;

typedef struct	s_mem {
	void			*ptr;
	struct s_mem	*next;
}				t_mem;

typedef struct	s_stack {
	int		*data;
	size_t	capacity;
	size_t	length;
}				t_stack;

typedef struct	s_glob {
	t_mem		**mem;
	char		*op_str[OP_NUMBER];
	t_bool		(*op_fn[OP_NUMBER])(struct s_glob*);
	t_op_enum	op_rev[OP_NUMBER];
	t_stack		*a;
	t_stack		*b;
}				t_glob;

typedef t_bool	(*t_op_fn)(t_glob*);

typedef struct	s_min_pos {
	t_stack_pos		pos;
	int				value;
}				t_min_pos;

#endif
