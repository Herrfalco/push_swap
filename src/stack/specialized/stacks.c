/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:12 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 13:45:14 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

static t_stack	*stack_from_args(t_mem **mem, int argc, char **argv)
{
	int		i;
	long	val;
	int		*stack_val;
	t_stack *stack;
	size_t	j;

	stack = stack_new(mem, VALUE);
	i = argc;
	while (--i > 0)
	{
		if ((val = my_atoi(argv[i])) == ATOI_ERR_RET)
			error_exit(mem, ATOI_ERR);
		stack_val = mem_alloc(mem, sizeof(int));
		*stack_val = val;
		j = -1;
		while (++j < stack->length)
			if (*(int *)stack->data[j] == (int)val)
				error_exit(mem, DUPLICATES_ERR);
		push_to_stack(mem, stack, stack_val);
	}
	return (stack);
}

t_2_stacks		*stacks_init(t_mem **mem, int argc, char **argv)
{
	t_2_stacks	*stacks;

	stacks = mem_alloc(mem, sizeof(t_2_stacks));
	stacks->a = stack_from_args(mem, argc, argv);
	stacks->b = stack_new(mem, VALUE);
	return (stacks);
}

void			stacks_free(t_mem **mem, t_2_stacks **stacks)
{
	stack_free(mem, &(*stacks)->a);
	stack_free(mem, &(*stacks)->b);
	mem_free_ptr(mem, *stacks);
	*stacks = NULL;
}
