/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:05 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/20 23:29:12 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static size_t		find_max_before(t_glob *glob, t_stack *stack, int val)
{
	int		max;
	size_t	max_i;
	int		tmp;
	size_t	i;

	if (!stack->length)
		error_exit(glob->mem, EMPTY_STACK_ERR);
	max_i = 0;
	max = *((int **)stack->data)[(i = 0)];
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

static t_op			*new_op(t_glob *glob, t_op op)
{
	t_op	*new_op;

	new_op = mem_alloc(glob->mem, sizeof(t_op));
	*new_op = op;
	return (new_op);
}

static t_stack		*get_op_stack(t_glob *glob, t_rots *rots)
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

static void			set_r_rots(t_rots *rots, size_t ra, size_t rb, size_t rr)
{
	rots->ra = ra;	
	rots->rb = rb;	
	rots->rr = rr;	
}

static void			set_rr_rots(t_rots *rots, size_t rra, size_t rrb, size_t rrr)
{
	rots->rra = rra;	
	rots->rrb = rrb;	
	rots->rrr = rrr;	
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
	size_t		place;
	t_rot_comb	move_nb[4];
	ssize_t		i;
	size_t		moves;
	t_rot_comb	best_moves;

	place = find_max_before(glob, stacks->b, *((int **)stacks->a->data)[idx]);
	set_r_rots(&rots, -idx + (stacks->a->length - 1), -place + (stacks->b->length - 1), 0);
	set_rr_rots(&rots, idx + 1, place + 1, 0);
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
	if (best_moves == RA_RB_RR)
	{
		if (rots.ra < rots.rb)
		{
			moves = rots.ra;
			set_rr_rots(&rots, 0, 0, 0);
			set_r_rots(&rots, 0, rots.rb - moves, moves);
		}
		else
		{
			moves = rots.rb;
			set_rr_rots(&rots, 0, 0, 0);
			set_r_rots(&rots, rots.ra - moves, 0, moves);
		}
	}
	else if (best_moves == RRA_RRB_RRR)
	{
		if (rots.rra < rots.rrb)
		{
			moves = rots.rb;
			moves = rots.rra;
			set_r_rots(&rots, 0, 0, 0);
			set_rr_rots(&rots, 0, rots.rrb - moves, moves);
		}
		else
		{
			moves = rots.rrb;
			set_r_rots(&rots, 0, 0, 0);
			set_rr_rots(&rots, rots.rra - moves, 0, moves);
		}
	}
	else if (best_moves == RA_RRB)
	{
		set_r_rots(&rots, rots.ra, 0, 0);
		set_rr_rots(&rots, 0, rots.rrb, 0);
	}
	else
	{
		set_r_rots(&rots, 0, rots.rb, 0);
		set_rr_rots(&rots, rots.rra, 0, 0);
	}
	return (get_op_stack(glob, &rots));
}

static t_stack		*best_moves(t_glob *glob, t_2_stacks *stacks)
{
	size_t		i;
	t_stack		*best_moves;
	t_stack		*tmp_moves;

	i = 0;
	best_moves = get_moves(glob, stacks, i);
	while (++i < stacks->a->length)
	{
		if ((tmp_moves = get_moves(glob, stacks, i))->length < best_moves->length)
		{
			stack_free(glob->mem, &best_moves);
			best_moves = tmp_moves;
		}
		else
			stack_free(glob->mem, &tmp_moves);
	}
	return (best_moves);
}

static t_stack		*final_moves(t_glob *glob, t_2_stacks *stacks)
{
	size_t		i;
	t_stack		*final_moves;
	int			max;
	size_t		max_i;

	i = 0;
	max = *((int **)stacks->b->data)[i];
	while (++i < stacks->b->length)
	{
		if (*((int **)stacks->b->data)[i] > max)
		{
			max = *((int **)stacks->b->data)[i];
			max_i = i;
		}
	}
	final_moves = stack_new(glob->mem, OPERATION);
	i = -1;
	while (++i < max_i * -1 + (stacks->b->length - 1))
		push_to_stack(glob->mem, final_moves, new_op(glob, RB));
	i = -1;
	while (++i < stacks->b->length)
		push_to_stack(glob->mem, final_moves, new_op(glob, PA));
	return (final_moves);
}

static void			concat_ops(t_glob *glob, t_stack *ops_1, t_stack *ops_2)
{
	while (ops_2->length)
	{
		rev_rotate(ops_2);
		push(glob->mem, ops_2, ops_1);
	}
	stack_free(glob->mem, &ops_2);
}

t_stack				*optimised_sort(t_glob *glob, t_2_stacks *stacks)
{
	t_stack		*result;
	t_stack		*new_moves;

	result = stack_new(glob->mem, OPERATION);
	if (stacks->a->length < 2)
		return (result);
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
