/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:17 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 11:48:03 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

t_stack	*stack_new(t_mem **mem)
{
	t_stack *stack;

	stack = mem_alloc(mem, sizeof(t_stack));
	stack->length = 0;
	stack->capacity = 0;
	stack->data = NULL;
	return (stack);
}

t_stack	*stack_from_args(t_mem **mem, int argc, char **argv)
{
	int		i;
	long	val;
	t_stack *stack;
	size_t	j;

	stack = stack_new(mem);
	i = argc - 1;
	while (i > 0)
	{
		if ((val = my_atoi(argv[i])) == ATOI_ERR_RET)
			error_exit(mem, ATOI_ERR);
		j = 0;
		while (j < stack->length)
		{
			if (stack->data[j] == (int)val)
				error_exit(mem, DUPLICATES_ERR);
			++j;
		}
		push_to_stack(mem, stack, (int)val);
		--i;
	}
	return (stack);
}

t_stack	*stack_cpy(t_mem **mem, t_stack *stack)
{
	t_stack *new_stack;
	size_t	i;

	new_stack = stack_new(mem);
	new_stack->length = stack->length;
	new_stack->capacity = stack->capacity;
	new_stack->data = mem_alloc(mem, sizeof(int) * stack->capacity);
	i = 0;
	while (i < stack->length)
	{
		new_stack->data[i] = stack->data[i];
		++i;
	}
	return (new_stack);
}

void	stack_free(t_mem **mem, t_stack **stack)
{
	if ((*stack)->data)
	{
		mem_free_ptr(mem, (*stack)->data);
	}
	mem_free_ptr(mem, *stack);
	(*stack) = NULL;
}
