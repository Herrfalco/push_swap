/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:26:54 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/21 20:25:49 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/includes.h"

void			concat_ops(t_glob *glob, t_stack *ops_1, t_stack *ops_2)
{
	while (ops_2->length)
	{
		rev_rotate(ops_2);
		push(glob->mem, ops_2, ops_1);
	}
	stack_free(glob->mem, &ops_2);
}

void			get_max(t_stack *stack, int *max, size_t *max_i)
{
	size_t		i;

	i = 0;
	*max = *((int **)stack->data)[i];
	*max_i = i;
	while (++i < stack->length)
	{
		if (*((int **)stack->data)[i] > *max)
		{
			*max = *((int **)stack->data)[i];
			*max_i = i;
		}
	}
}

static t_stack	*get_op_stack(t_glob *glob, t_rots *rots)
{
	ssize_t		i;
	t_stack		*op_stack;

	op_stack = stack_new(glob->mem, OPERATION);
	i = -1;
	while (++i < (ssize_t)rots->ra)
		push_to_stack(glob->mem, op_stack, new_op(glob, RA));
	i = -1;
	while (++i < (ssize_t)rots->rb)
		push_to_stack(glob->mem, op_stack, new_op(glob, RB));
	i = -1;
	while (++i < (ssize_t)rots->rr)
		push_to_stack(glob->mem, op_stack, new_op(glob, RR));
	i = -1;
	while (++i < (ssize_t)rots->rra)
		push_to_stack(glob->mem, op_stack, new_op(glob, RRA));
	i = -1;
	while (++i < (ssize_t)rots->rrb)
		push_to_stack(glob->mem, op_stack, new_op(glob, RRB));
	i = -1;
	while (++i < (ssize_t)rots->rrr)
		push_to_stack(glob->mem, op_stack, new_op(glob, RRR));
	push_to_stack(glob->mem, op_stack, new_op(glob, PB));
	return (op_stack);
}

t_stack			*rots_to_op_stack(t_glob *glob, t_rots *rots,
	t_rot_comb best_moves)
{
	if (best_moves == RA_RB_RR)
	{
		if (rots->ra < rots->rb)
			reset_set_r_rots(rots, 0, rots->rb - rots->ra, rots->ra);
		else
			reset_set_r_rots(rots, rots->ra - rots->rb, 0, rots->rb);
	}
	else if (best_moves == RRA_RRB_RRR)
	{
		if (rots->rra < rots->rrb)
			reset_set_rr_rots(rots, 0, rots->rrb - rots->rra, rots->rra);
		else
			reset_set_rr_rots(rots, rots->rra - rots->rrb, 0, rots->rrb);
	}
	else if (best_moves == RA_RRB)
	{
		set_r_rots(rots, rots->ra, 0, 0);
		set_rr_rots(rots, 0, rots->rrb, 0);
	}
	else
	{
		set_r_rots(rots, 0, rots->rb, 0);
		set_rr_rots(rots, rots->rra, 0, 0);
	}
	return (get_op_stack(glob, rots));
}
