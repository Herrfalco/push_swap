/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:05 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/22 10:50:42 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

static ssize_t	get_asc_entropy(t_stack *stack)
{
	size_t	ent;

	ent = 0;
	if (*((int **)stack->data)[0] < *((int **)stack->data)[1])
		++ent;
	if (*((int **)stack->data)[1] < *((int **)stack->data)[2])
		++ent;
	if (*((int **)stack->data)[2] < *((int **)stack->data)[0])
		++ent;
	return (ent);
}

t_stack			*small_sort(t_glob *glob, t_2_stacks *stacks)
{
	t_stack		*op_stack;

	op_stack = stack_new(glob->mem, OPERATION);
	if (get_asc_entropy(stacks->a) > 1)
		stack_push_exec(glob, stacks, op_stack, SA);
	while (stack_entropy(stacks->a))
		stack_push_exec(glob, stacks, op_stack, RRA);
	return (op_stack);
}
