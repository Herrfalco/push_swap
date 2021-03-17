/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:05 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 11:12:19 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static int	get_min_on_top(t_glob *glob, t_stack *stack, t_stack **result)
{
	int				min_val;
	int				tmp;
	t_stack_pos		pos;

	min_val = top_of_stack(glob->mem, stack);
	pos = TOP;
	if (stack->length > 1 && (tmp = bot_of_stack(glob->mem, stack)) < min_val)
	{
		pos = BOTTOM;
		min_val = tmp;
	}
	else if (stack->length > 2
		&& (tmp = sec_of_stack(glob->mem, stack)) < min_val)
	{
		pos = SECOND;
		min_val = tmp;
	}
	if (pos == BOTTOM)
		stack_push_exec(glob, *result, RRA);
	else if (pos == SECOND)
		stack_push_exec(glob, *result, SA);
	return (min_val);
}

void		insertion_sort(t_glob *glob_base, t_stack **result)
{
	t_glob		*glob;
	int			min;

	glob = glob_cpy(glob_base);
	*result = stack_new(glob->mem);
	while (!sorted(glob))
	{
		min = get_min_on_top(glob, glob->a, result);
		if (sorted(glob))
			break ;
		if (!glob->b->length || min > top_of_stack(glob->mem, glob->b))
			stack_push_exec(glob, *result, PB);
		else if (min < bot_of_stack(glob->mem, glob->b))
			stack_double_push_exec(glob, *result, PB, RB);
		else
		{
			stack_push_exec(glob, *result, RA);
			while (glob->b->length && top_of_stack(glob->mem, glob->b) > min)
				stack_push_exec(glob, *result, PA);
			stack_push_exec(glob, *result, RRA);
		}
	}
	stack_concat(glob, *result);
	glob_free_cpy(&glob);
}
