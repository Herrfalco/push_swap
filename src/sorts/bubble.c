/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:54 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 21:29:44 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	bubble_sort(t_glob *glob_base, t_stack **result)
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
		if (cur_stack == glob->a)
		{
			if (top_of_stack(glob->mem, glob->a) >
				sec_of_stack(glob->mem, glob->a))
			{
				push_to_stack(glob->mem, *result, SA);
				sa(glob);
			}
			else
			{
				push_to_stack(glob->mem, *result, PB);
				pb(glob);
			}
		}
		else
		{
			if (top_of_stack(glob->mem, glob->b) <
				sec_of_stack(glob->mem, glob->b))
			{
				push_to_stack(glob->mem, *result, SB);
				sb(glob);
			}
			else
			{
				push_to_stack(glob->mem, *result, PA);
				pa(glob);
			}
		}
	}
	stack_concat(glob, *result);
	glob_free_cpy(&glob);
}
