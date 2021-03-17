/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:15 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 23:44:56 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

t_bool	sorted(t_glob *glob)
{
	return (!stack_entropy(glob->a, ASCENDING)
		&& !stack_entropy(glob->b, DESCENDING)
		&& (!glob->a->length || !glob->b->length
		|| top_of_stack(glob->mem, glob->a)
		> top_of_stack(glob->mem, glob->b)));
}

void	stack_concat(t_glob *glob, t_stack *result)
{
	while (glob->b->length)
	{
		push_to_stack(glob->mem, result, PA);
		pa(glob);
	}
}

void	stack_push_exec(t_glob *glob, t_stack *result, t_op_enum op)
{
	push_to_stack(glob->mem, result, op);
	glob->op_fn[op](glob);
}

void	stack_double_push_exec(t_glob *glob, t_stack *result, t_op_enum op_1,
	t_op_enum op_2)
{
	stack_push_exec(glob, result, op_1);
	stack_push_exec(glob, result, op_2);
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
			if (stack->data[i] < stack->data[i + 1])
				++entropy;
		}
		else
		{
			if (stack->data[i] > stack->data[i + 1])
				++entropy;
		}
	}
	return (entropy);
}
