/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:02 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 21:29:19 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	glob_init(t_glob *glob, int argc, char **argv)
{
	static char		*init_op_str[] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr",
	};
	static t_op_fn	init_op_fn[] = {
		sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr,
	};
	static int		init_op_rev[] = {
		SA, SB, SS, PB, PA,
		RRA, RRB, RRR, RA, RB,
		RR,
	};
	size_t			i;

	glob->mem = malloc(sizeof(t_mem *));
	*glob->mem = NULL;
	i = 0;
	while (i < OP_NUMBER)
	{
		glob->op_str[i] = str_cpy(glob->mem, init_op_str[i]);
		++i;
	}
	i = 0;
	while (i < OP_NUMBER)
	{
		glob->op_fn[i] = init_op_fn[i];
		++i;
	}
	i = 0;
	while (i < OP_NUMBER)
	{
		glob->op_rev[i] = init_op_rev[i];
		++i;
	}
	glob->a = stack_from_args(glob->mem, argc, argv);
	glob->b = stack_new(glob->mem);
}

t_glob	*glob_cpy(t_glob *glob)
{
	t_glob	*new_glob;
	size_t	i;

	new_glob = mem_alloc(glob->mem, sizeof(t_glob));
	new_glob->mem = glob->mem;
	i = 0;
	while (i < OP_NUMBER)
	{
		new_glob->op_str[i] = glob->op_str[i];
		++i;
	}
	i = 0;
	while (i < OP_NUMBER)
	{
		new_glob->op_fn[i] = glob->op_fn[i];
		++i;
	}
	i = 0;
	while (i < OP_NUMBER)
	{
		new_glob->op_rev[i] = glob->op_rev[i];
		++i;
	}
	new_glob->a = stack_cpy(glob->mem, glob->a);
	new_glob->b = stack_cpy(glob->mem, glob->b);
	return (new_glob);
}

void	glob_free_cpy(t_glob **glob)
{
	stack_free((*glob)->mem, &(*glob)->a);
	stack_free((*glob)->mem, &(*glob)->b);
	mem_free_ptr((*glob)->mem, *glob);
	*glob = NULL;
}

void	glob_free(t_glob *glob)
{
	mem_free_all(glob->mem);
	free(glob->mem);
}
