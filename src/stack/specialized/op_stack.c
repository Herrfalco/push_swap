/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:12 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 23:12:37 by fcadet           ###   ########.fr       */
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

static void		print_stacks(t_glob *glob, t_2_stacks *stacks)
{
	write(1, "A: ", 3);
	display_stack(glob, stacks->a);
	write(1, "\nB: ", 4);
	display_stack(glob, stacks->b);
	write(1, "\n-----\n", 7);
}

void			exec_op_stack(t_glob *glob, t_stack *op_stack, t_2_stacks *stacks)
{
	size_t i;

	if (DISPLAY_STACKS)
		write(1, "-----\n", 6);
	i = -1;
	while (++i < op_stack->length)
	{
		if (DISPLAY_STACKS)
			print_stacks(glob, stacks);
		glob->op_fn[*((t_op **)op_stack->data)[i]](glob, stacks);
	}
	print_stacks(glob, stacks);
}
