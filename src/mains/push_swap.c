/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:14 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/22 10:49:56 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int		main(int argc, char **argv)
{
	t_glob		glob;
	t_2_stacks	*stacks;
	t_stack		*result;

	glob_init(&glob);
	stacks = stacks_init(glob.mem, argc, argv);
	if (stack_entropy(stacks->a))
	{
		if (stacks->a->length == 3)
			result = small_sort(&glob, stacks);
		else if (stacks->a->length > 5)
			result = optimised_sort(&glob, stacks);
		else
			result = backtrack_sort(&glob, stacks);
		display_stack(&glob, result);
	}
	glob_free(&glob);
	return (0);
}
