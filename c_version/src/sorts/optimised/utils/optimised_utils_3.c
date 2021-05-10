/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:45:38 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/21 12:26:05 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/includes.h"

void			set_r_rots(t_rots *rots, size_t ra, size_t rb, size_t rr)
{
	rots->ra = ra;
	rots->rb = rb;
	rots->rr = rr;
}

void			set_rr_rots(t_rots *rots, size_t rra, size_t rrb, size_t rrr)
{
	rots->rra = rra;
	rots->rrb = rrb;
	rots->rrr = rrr;
}

void			set_raw_rots(t_glob *glob, t_2_stacks *stacks, t_rots *rots,
	size_t idx)
{
	size_t		place;

	place = find_max_before(glob, stacks->b, *((int **)stacks->a->data)[idx]);
	set_r_rots(rots, -idx + (stacks->a->length - 1),
		-place + (stacks->b->length - 1), 0);
	set_rr_rots(rots, idx + 1, place + 1, 0);
}

void			reset_set_r_rots(t_rots *rots, size_t ra, size_t rb, size_t rr)
{
	set_rr_rots(rots, 0, 0, 0);
	set_r_rots(rots, ra, rb, rr);
}

void			reset_set_rr_rots(t_rots *rots, size_t rra, size_t rrb,
	size_t rrr)
{
	set_r_rots(rots, 0, 0, 0);
	set_rr_rots(rots, rra, rrb, rrr);
}
