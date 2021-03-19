/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:12 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 15:57:59 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

void			push_op_to_stack(t_glob *glob, t_stack *stack, char *str)
{
	size_t	i;
	t_op	*val;

	i = -1;
	while (++i < OP_NUMBER)
	{
		if (!str_cmp(str, glob->op_str[i]))
		{
			val = mem_alloc(glob->mem, sizeof(t_op));
			*val = i;
			push_to_stack(glob->mem, stack, val);
			return ;
		}
	}
	error_exit(glob->mem, OP_STR_ERR);
}

void			exec_op_stack(t_glob *glob, t_stack *op_stack, t_2_stacks *stacks)
{
	size_t i;

	i = -1;
	while (++i < op_stack->length)
		glob->op_fn[*((t_op **)op_stack->data)[i]](glob, stacks);
}
