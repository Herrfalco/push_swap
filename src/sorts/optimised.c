/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:05 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/20 15:25:18 by fcadet           ###   ########.fr       */
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

static t_stack		*get_op_stack(t_glob *glob, size_t ra_nb, size_t rb_nb, size_t rr_nb)
{
	ssize_t		i;
	t_stack		*op_stack;

	op_stack = stack_new(glob->mem, OPERATION);
	i = -1;
	while (++i < (ssize_t)ra_nb)
		push_to_stack(glob->mem, op_stack, new_op(glob, RA));
	i = -1;
	while (++i < (ssize_t)rb_nb)
		push_to_stack(glob->mem, op_stack, new_op(glob, RB));
	i = -1;
	while (++i < (ssize_t)rr_nb)
		push_to_stack(glob->mem, op_stack, new_op(glob, RR));
	push_to_stack(glob->mem, op_stack, new_op(glob, PB));
	return (op_stack);
}

static t_stack		*get_moves(t_glob *glob, t_2_stacks *stacks, size_t idx)
{
	size_t		ra_nb;
	size_t		rb_nb;
	size_t		rr_nb;

	ra_nb = idx * -1 + (stacks->a->length - 1);
	rb_nb = find_max_before(glob, stacks->b, *((int **)stacks->a->data)[idx])
		* -1 + (stacks->b->length - 1);
	if (ra_nb < rb_nb)
	{
		rr_nb = ra_nb;
		rb_nb -= ra_nb;
		ra_nb = 0;
	}
	else
	{
		rr_nb = rb_nb;
		ra_nb -= rb_nb;
		rb_nb = 0;
	}
	return (get_op_stack(glob, ra_nb, rb_nb, rr_nb));
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
	if (DISPLAY_STACKS)
	{
		write(1, "-----\n", 6);
		print_stacks(glob, stacks);
	}
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
