/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:22:09 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/21 12:29:40 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/includes.h"

size_t				find_max_before(t_glob *glob, t_stack *stack, int val)
{
	int		max;
	size_t	max_i;
	int		tmp;
	size_t	i;

	if (!stack->length)
		error_exit(glob->mem, EMPTY_STACK_ERR);
	i = 0;
	max_i = i;
	max = *((int **)stack->data)[i];
	while (++i < stack->length)
	{
		tmp = *((int **)stack->data)[i];
		if ((tmp < val && (max > val || tmp > max)) || (tmp > max && max > val))
		{
			max = tmp;
			max_i = i;
		}
	}
	return (max_i);
}

static void			get_move_nb(t_rots *rots, t_rot_comb *move_nb)
{
	move_nb[RA_RB_RR] = rots->ra < rots->rb ? rots->rb : rots->ra;
	move_nb[RRA_RRB_RRR] = rots->rra < rots->rrb ? rots->rrb : rots->rra;
	move_nb[RA_RRB] = rots->ra + rots->rrb;
	move_nb[RRA_RB] = rots->rra + rots->rb;
}

static t_stack		*get_moves(t_glob *glob, t_2_stacks *stacks, size_t idx)
{
	t_rots		rots;
	t_rot_comb	move_nb[4];
	ssize_t		i;
	size_t		moves;
	t_rot_comb	best_moves;

	set_raw_rots(glob, stacks, &rots, idx);
	get_move_nb(&rots, move_nb);
	best_moves = RA_RB_RR;
	moves = move_nb[best_moves];
	i = 0;
	while (++i < 4)
	{
		if (move_nb[i] < moves)
		{
			best_moves = i;
			moves = move_nb[best_moves];
		}
	}
	return (rots_to_op_stack(glob, &rots, best_moves));
}

t_stack				*best_moves(t_glob *glob, t_2_stacks *stacks)
{
	size_t		i;
	t_stack		*best_moves;
	t_stack		*tmp_moves;

	i = 0;
	best_moves = get_moves(glob, stacks, i);
	while (++i < stacks->a->length)
	{
		if ((tmp_moves = get_moves(glob, stacks, i))->length
			< best_moves->length)
		{
			stack_free(glob->mem, &best_moves);
			best_moves = tmp_moves;
		}
		else
			stack_free(glob->mem, &tmp_moves);
	}
	return (best_moves);
}

t_stack				*final_moves(t_glob *glob, t_2_stacks *stacks)
{
	size_t		i;
	t_stack		*final_moves;
	int			max;
	size_t		max_i;

	get_max(stacks->b, &max, &max_i);
	final_moves = stack_new(glob->mem, OPERATION);
	i = -1;
	if (-max_i + (stacks->b->length - 1) > max_i + 1)
	{
		while (++i < max_i + 1)
			push_to_stack(glob->mem, final_moves, new_op(glob, RRB));
	}
	else
		while (++i < -max_i + (stacks->b->length - 1))
			push_to_stack(glob->mem, final_moves, new_op(glob, RB));
	i = -1;
	while (++i < stacks->b->length)
		push_to_stack(glob->mem, final_moves, new_op(glob, PA));
	return (final_moves);
}
