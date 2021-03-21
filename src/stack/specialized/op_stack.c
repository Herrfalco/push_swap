/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:12 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/21 21:55:11 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

t_op			*new_op(t_glob *glob, t_op op)
{
	t_op	*new_op;

	new_op = mem_alloc(glob->mem, sizeof(t_op));
	*new_op = op;
	return (new_op);
}

void		push_op_to_stack(t_glob *glob, t_stack *stack, char *str)
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

//a supprimer
void		print_stacks(t_glob *glob, t_2_stacks *stacks)
{
	write(1, "A: ", 3);
	display_stack(glob, stacks->a);
	write(1, "\nB: ", 4);
	display_stack(glob, stacks->b);
	write(1, "\n", 1);
}

void		exec_op_stack(t_glob *glob, t_stack *op_stack, t_2_stacks *stacks)
{
	size_t i;

	i = -1;
	while (++i < op_stack->length)
		glob->op_fn[*((t_op **)op_stack->data)[i]](glob, stacks);
}

t_stack		*copy_op_stack(t_glob *glob, t_stack *op_stack)
{
	t_stack		*copy;
	ssize_t		i;

	copy = stack_new(glob->mem, OPERATION);
	i = -1;
	while (++i < (ssize_t)op_stack->length)
		push_to_stack(glob->mem, copy, new_op(glob,
			*((int **)op_stack->data)[i]));
	return (copy);
}
