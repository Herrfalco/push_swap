/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:05 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 21:37:23 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static t_min_pos	stack_min_pos(t_mem **mem, t_stack *stack)
{
	t_min_pos		min;
	int				tmp;

	min.pos = NONE;
	min.value = 0;
	if (!stack->length)
		return (min);
	min.value = top_of_stack(mem, stack);
	min.pos = TOP;
	if (stack->length > 1 && (tmp = bot_of_stack(mem, stack)) < min.value)
	{
		min.value = tmp;
		min.pos = BOTTOM;
	}
	if (stack->length > 2 && (tmp = sec_of_stack(mem, stack)) < min.value)
	{
		min.value = tmp;
		min.pos = SECOND;
	}
	return (min);
}

void				insertion_sort(t_glob *glob_base, t_stack **result)
{
	t_glob		*glob;
	t_min_pos	min;

	glob = glob_cpy(glob_base);
	*result = stack_new(glob->mem);
	while (!sorted(glob))
	{
		min = stack_min_pos(glob->mem, glob->a);
		if (min.pos == BOTTOM)
			stack_push_exec(glob, *result, RRA);
		else if (min.pos == SECOND)
			stack_push_exec(glob, *result, SA);
		if (sorted(glob))
			break ;
		if (!glob->b->length || min.value > top_of_stack(glob->mem, glob->b))
			stack_push_exec(glob, *result, PB);
		else if (min.value < bot_of_stack(glob->mem, glob->b))
		{
			stack_push_exec(glob, *result, PB);
			stack_push_exec(glob, *result, RB);
		}
		else
		{
			stack_push_exec(glob, *result, RA);
			while (glob->b->length
				&& top_of_stack(glob->mem, glob->b) > min.value)
				stack_push_exec(glob, *result, PA);
			stack_push_exec(glob, *result, RRA);
		}
	}
	stack_concat(glob, *result);
	glob_free_cpy(&glob);
}
