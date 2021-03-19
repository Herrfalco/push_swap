/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:05 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 22:23:26 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static int	get_min_on_top(t_glob *glob, t_2_stacks *stacks, t_stack **result)
{
	int			min_val;
	int			tmp;
	t_pos		pos;

	min_val = *((int **)stacks->a->data)[stacks->a->length - 1];
	pos = TOP;
	if (stacks->a->length > 1
		&& (tmp = *((int **)stacks->a->data)[0]) < min_val)
	{
		pos = BOTTOM;
		min_val = tmp;
	}
	else if (stacks->a->length > 2
		&& (tmp = *((int **)stacks->a->data)[stacks->a->length - 2]) < min_val)
	{
		pos = SECOND;
		min_val = tmp;
	}
	if (pos == BOTTOM)
		stack_push_exec(glob, stacks, *result, RRA);
	else if (pos == SECOND)
		stack_push_exec(glob, stacks, *result, SA);
	return (min_val);
}

static void	to_end_of_b(t_glob *glob, t_2_stacks *stacks, t_stack *result)
{
	stack_push_exec(glob, stacks, result, PB);
	stack_push_exec(glob, stacks, result, RB);
}

t_stack		*insertion_sort(t_glob *glob, t_2_stacks *stacks)
{
	int			min;
	t_stack		*result;

	result = stack_new(glob->mem, OPERATION);
	while (!sorted(stacks))
	{
		min = get_min_on_top(glob, stacks, &result);
		if (sorted(stacks))
			break ;
		if (!stacks->b->length
			|| min > *((int **)stacks->b->data)[stacks->b->length - 1])
			stack_push_exec(glob, stacks, result, PB);
		else if (min < *((int **)stacks->b->data)[0])
			to_end_of_b(glob, stacks, result);
		else
		{
			stack_push_exec(glob, stacks, result, RA);
			while (stacks->b->length
				&& *((int **)stacks->b->data)[stacks->b->length - 1] > min)
				stack_push_exec(glob, stacks, result, PA);
			stack_push_exec(glob, stacks, result, RRA);
		}
	}
	stacks_concat(glob, stacks, result);
	return (result);
}
