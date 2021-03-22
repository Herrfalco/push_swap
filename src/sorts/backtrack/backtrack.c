/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:05 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/22 10:28:13 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

static void		revert_push_exec(t_glob *glob, t_2_stacks *stacks,
	t_stack *op_stack)
{
	t_op	*last_op;

	last_op = pop_from_stack(glob->mem, op_stack);
	glob->op_fn[glob->op_rev[*last_op]](glob, stacks);
	mem_free_ptr(glob->mem, last_op);
}

static t_bool	useless_move(t_glob *glob, t_2_stacks *stacks,
	t_stack *op_stack, t_op op)
{
	t_op	last_op;

	if (stacks->a->length < 2 || stacks->b->length < 2)
		if (op == RRR || op == RR || op == SS)
			return (TRUE);
	if (stacks->a->length < 2)
		if (op == SA || op == RA || op == RRA)
			return (TRUE);
	if (stacks->b->length < 2)
		if (op == SB || op == RB || op == RRB)
			return (TRUE);
	if ((!stacks->a->length && op == PB) || (!stacks->b->length && op == PA))
		return (TRUE);
	if (!op_stack->length)
		return (FALSE);
	last_op = *((t_op **)op_stack->data)[op_stack->length - 1];
	if (op == glob->op_rev[last_op])
		return (TRUE);
	return (FALSE);
}

static t_stack	*rec_backtrack_sort(t_glob *glob, t_2_stacks *stacks,
	t_stack *op_stack)
{
	ssize_t		i;
	t_stack		*result;

	if (op_stack->length > MAX_BACKTRACK)
		return (NULL);
	if (!stack_entropy(stacks->a) && !stacks->b->length)
		return (copy_op_stack(glob, op_stack));
	i = -1;
	while (++i < OP_NUMBER)
	{
		if (useless_move(glob, stacks, op_stack, i) == TRUE)
			continue ;
		stack_push_exec(glob, stacks, op_stack, i);
		if ((result = rec_backtrack_sort(glob, stacks, op_stack)))
			return (result);
		revert_push_exec(glob, stacks, op_stack);
	}
	return (NULL);
}

t_stack			*backtrack_sort(t_glob *glob, t_2_stacks *stacks)
{
	t_stack		*op_stack;

	op_stack = stack_new(glob->mem, OPERATION);
	return (rec_backtrack_sort(glob, stacks, op_stack));
}
