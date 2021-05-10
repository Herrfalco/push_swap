/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:17 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/20 13:50:50 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

t_stack	*stack_new(t_mem **mem, t_type type)
{
	t_stack *stack;

	stack = mem_alloc(mem, sizeof(t_stack));
	stack->length = 0;
	stack->capacity = 0;
	stack->data = NULL;
	stack->type = type;
	return (stack);
}

void	stack_free(t_mem **mem, t_stack **stack)
{
	ssize_t		i;

	if ((*stack)->data)
	{
		i = -1;
		while (++i < (ssize_t)(*stack)->length)
			mem_free_ptr(mem, (*stack)->data[i]);
		mem_free_ptr(mem, (*stack)->data);
	}
	mem_free_ptr(mem, *stack);
	(*stack) = NULL;
}

void	push_to_stack(t_mem **mem, t_stack *stack, void *val)
{
	void	**new_data;
	size_t	i;

	if (stack->length + 1 > stack->capacity)
	{
		stack->capacity = stack->capacity ? stack->capacity * 2 : 1;
		new_data = mem_alloc(mem, stack->capacity * sizeof(void *));
		if (stack->data)
		{
			i = -1;
			while (++i < stack->length)
				new_data[i] = stack->data[i];
			mem_free_ptr(mem, stack->data);
		}
		stack->data = new_data;
	}
	stack->data[stack->length++] = val;
}

void	*pop_from_stack(t_mem **mem, t_stack *stack)
{
	if (!stack->length)
		error_exit(mem, EMPTY_STACK_ERR);
	--stack->length;
	return (stack->data[stack->length]);
}

void	display_stack(t_glob *glob, t_stack *stack)
{
	ssize_t	i;
	char	*str;

	if (!stack)
		return ;
	i = -1;
	while (++i < (ssize_t)stack->length)
	{
		if (stack->type == OPERATION)
		{
			str = glob->op_str[*((t_op **)stack->data)[i]];
			write(1, str, str_len(str));
			write(1, "\n", 1);
		}
		else
		{
			str = my_itoa(glob, *((int **)stack->data)[i]);
			write(1, str, str_len(str));
			write(1, " ", 1);
			mem_free_ptr(glob->mem, str);
		}
	}
}
