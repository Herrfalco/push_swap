/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:44 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 11:00:14 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

#endif
