/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:44 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/18 22:09:17 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_mem {
	void			*ptr;
	struct s_mem	*next;
}				t_mem;

typedef struct	s_stack {
	void	**data;
	size_t	capacity;
	size_t	length;
	t_type	type;
}				t_stack;

typedef struct	s_2_stacks {
	t_stack		*a;
	t_stack		*b;
}				t_2_stacks;

typedef struct	s_glob {
	t_mem		**mem;
	char		*op_str[OP_NUMBER];
	void		(*op_fn[OP_NUMBER])(struct s_glob*, t_2_stacks *stacks);
	t_op		op_rev[OP_NUMBER];
}				t_glob;

typedef void	(*t_op_fn)(t_glob*, t_2_stacks *stacks);

#endif
