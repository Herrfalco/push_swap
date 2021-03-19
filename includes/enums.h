/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:44 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 14:24:53 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum	e_bool {
	FALSE,
	TRUE,
}				t_bool;

typedef enum	e_type {
	VALUE,
	OPERATION,
}				t_type;

typedef enum	e_order {
	ASCENDING,
	DESCENDING,
}				t_order;

typedef enum	e_pos {
	TOP,
	SECOND,
	BOTTOM,
}				t_pos;

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
	DUPLICATES_ERR,
	ATOI_ERR,
	READ_ERR,
	OP_LINE_RET_ERR,
	OP_TOO_LONG,
	OP_STR_ERR,
	EMPTY_STACK_ERR,
	OUT_OF_STACK_ERR,
	NOT_ENOUGH_ELEM,
}				t_err;

typedef enum	e_op {
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
}				t_op;

#endif
