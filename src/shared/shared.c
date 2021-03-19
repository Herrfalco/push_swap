/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:15 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 16:47:37 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

t_bool	sorted(t_2_stacks *stacks)
{
	return (!stack_entropy(stacks->a, ASCENDING)
		&& !stack_entropy(stacks->b, DESCENDING)
		&& (!stacks->a->length || !stacks->b->length
		|| *((int **)stacks->a->data)[stacks->a->length - 1]
		> *((int **)stacks->b->data)[stacks->b->length - 1]));
}

void	stacks_concat(t_glob *glob, t_2_stacks *stacks, t_stack *result)
{
	t_op	*op;

	while (stacks->b->length)
	{
		op = mem_alloc(glob->mem, sizeof(t_op));
		*op = PA;
		push_to_stack(glob->mem, result, op);
		pa(glob, stacks);
	}
}

void	stack_push_exec(t_glob *glob, t_2_stacks *stacks, t_stack *result, t_op op)
{
	t_op	*new_op;

	new_op = mem_alloc(glob->mem, sizeof(t_op));
	*new_op = op;
	push_to_stack(glob->mem, result, new_op);
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
