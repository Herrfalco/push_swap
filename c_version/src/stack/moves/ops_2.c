/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:54:07 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 14:44:57 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

void	ra(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	rotate(stacks->a);
}

void	rb(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	rotate(stacks->b);
}

void	rr(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	rotate(stacks->a);
	rotate(stacks->b);
}

void	rra(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	rev_rotate(stacks->a);
}

void	rrb(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	rev_rotate(stacks->b);
}
