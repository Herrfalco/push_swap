/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:15 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/21 21:05:32 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	stacks_concat(t_glob *glob, t_2_stacks *stacks, t_stack *result)
{
	t_op	*op;

	while (stacks->b->length)
	{
		op = new_op(glob, PA);
		push_to_stack(glob->mem, result, op);
		pa(glob, stacks);
	}
}

void	stack_push_exec(t_glob *glob, t_2_stacks *stacks,
	t_stack *result, t_op op)
{
	t_op	*new_op_val;

	new_op_val = new_op(glob, op);
	push_to_stack(glob->mem, result, new_op_val);
	glob->op_fn[op](glob, stacks);
}

size_t	stack_entropy(t_stack *stack, t_order order)
{
	size_t	entropy;
	size_t	i;

	entropy = 0;
	if (stack->length < 2)
		return (entropy);
	i = -1;
	while (++i < stack->length - 1)
	{
		if (order == ASCENDING)
		{
			if (*((int **)stack->data)[i] < *((int **)stack->data)[i + 1])
				++entropy;
		}
		else
		{
			if (*((int **)stack->data)[i] > *((int **)stack->data)[i + 1])
				++entropy;
		}
	}
	return (entropy);
}
