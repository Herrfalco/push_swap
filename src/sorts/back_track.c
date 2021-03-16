/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:52 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 22:17:39 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static void	rec_back_track(t_glob *glob, t_stack *op_stack, t_stack **result,
	size_t max_rec)
{
	size_t	i;

	if (op_stack->length)
	{
		if (glob->op_fn[top_of_stack(glob->mem,
			op_stack)](glob) == FALSE)
		{
			pop_from_stack(glob->mem, op_stack);
			return ;
		}
	}
	if (!stack_entropy(glob->a, ASCENDING) &&
		!glob->b->length)
	{
		*result = stack_cpy(glob->mem, op_stack);
		return ;
	}
	if (op_stack->length <= max_rec)
	{
		i = 0;
		while (i < OP_NUMBER)
		{
			if (op_stack->length &&
				(top_of_stack(glob->mem, op_stack) ==
				(int)glob->op_rev[i]))
			{
				++i;
				continue ;
			}
			push_to_stack(glob->mem, op_stack, i);
			rec_back_track(glob, op_stack, result, max_rec);
			if (*result)
				return ;
			++i;
		}
	}
	if (op_stack->length)
		glob->op_fn[glob->op_rev[pop_from_stack(glob->mem,
			op_stack)]](glob);
}

#include <stdio.h>
void		back_track(t_glob *glob, t_stack **result)
{
	t_stack		*op_stack;
	size_t		max_rec;

	max_rec = 0;
	op_stack = stack_new(glob->mem);
	while (!*result)
	{
		if (max_rec >= MAX_RECURSION)
			break ;
		rec_back_track(glob, op_stack, result, max_rec++);
	}
	stack_free(glob->mem, &op_stack);
}
