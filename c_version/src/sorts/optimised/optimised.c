/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:05 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/21 21:54:08 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

t_stack				*optimised_sort(t_glob *glob, t_2_stacks *stacks)
{
	t_stack		*result;
	t_stack		*new_moves;

	result = stack_new(glob->mem, OPERATION);
	stack_push_exec(glob, stacks, result, PB);
	while (stacks->a->length)
	{
		new_moves = best_moves(glob, stacks);
		exec_op_stack(glob, new_moves, stacks);
		concat_ops(glob, result, new_moves);
	}
	new_moves = final_moves(glob, stacks);
	exec_op_stack(glob, new_moves, stacks);
	concat_ops(glob, result, new_moves);
	return (result);
}
