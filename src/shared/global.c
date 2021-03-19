/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:02 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 15:11:02 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	glob_init(t_glob *glob)
{
	static char		*init_op_str[] = { "sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr",
	};
	static t_op_fn	init_op_fn[] = { sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
		rrr,
	};
	static int		init_op_rev[] = { SA, SB, SS, PB, PA, RRA, RRB, RRR, RA, RB,
		RR,
	};
	size_t			i;

	glob->mem = malloc(sizeof(t_mem *));
	*glob->mem = NULL;
	i = -1;
	while (++i < OP_NUMBER)
		glob->op_str[i] = str_cpy(glob->mem, init_op_str[i]);
	i = -1;
	while (++i < OP_NUMBER)
		glob->op_fn[i] = init_op_fn[i];
	i = -1;
	while (++i < OP_NUMBER)
		glob->op_rev[i] = init_op_rev[i];
}

void	glob_free(t_glob *glob)
{
	mem_free_all(glob->mem);
	free(glob->mem);
}
