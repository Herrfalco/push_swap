/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:10 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 14:44:44 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

void	sa(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	swap(stacks->a);
}

void	sb(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	swap(stacks->b);
}

void	ss(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	swap(stacks->a);
	swap(stacks->b);
}

void	pa(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	push(glob->mem, stacks->b, stacks->a);
}

void	pb(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	push(glob->mem, stacks->a, stacks->b);
}
