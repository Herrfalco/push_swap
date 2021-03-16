/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:54 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 23:01:57 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static void		swap_or_push(t_glob *glob, t_stack *cur_stack, t_stack *result)
{
	if (cur_stack == glob->a)
	{
		if (top_of_stack(glob->mem, cur_stack)
			> sec_of_stack(glob->mem, cur_stack))
			stack_push_exec(glob, result, SA);
		else
			stack_push_exec(glob, result, PB);
	}
	else
	{
		if (top_of_stack(glob->mem, cur_stack)
			< sec_of_stack(glob->mem, cur_stack))
			stack_push_exec(glob, result, SB);
		else
			stack_push_exec(glob, result, PA);
	}
}

void			bubble_sort(t_glob *glob_base, t_stack **result)
{
	t_glob	*glob;
	t_stack *cur_stack;
	size_t	remainder;

	glob = glob_cpy(glob_base);
	cur_stack = glob->a;
	remainder = 1;
	*result = stack_new(glob->mem);
	while (!sorted(glob))
	{
		if (cur_stack->length == remainder)
		{
			if (cur_stack == glob->b)
				++remainder;
			cur_stack = cur_stack == glob->a
				? glob->b : glob->a;
		}
		swap_or_push(glob, cur_stack, *result);
	}
	stack_concat(glob, *result);
	glob_free_cpy(&glob);
}
