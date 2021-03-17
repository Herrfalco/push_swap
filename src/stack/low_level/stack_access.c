/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:17 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 11:47:55 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

void	push_to_stack(t_mem **mem, t_stack *stack, int val)
{
	int		*new_data;
	size_t	i;

	if (stack->length + 1 > stack->capacity)
	{
		stack->capacity = stack->capacity ? stack->capacity * 2 : 1;
		new_data = mem_alloc(mem, stack->capacity * sizeof(int));
		if (stack->data)
		{
			i = 0;
			while (i < stack->length)
			{
				new_data[i] = stack->data[i];
				++i;
			}
			mem_free_ptr(mem, stack->data);
		}
		stack->data = new_data;
	}
	stack->data[stack->length++] = val;
}

int		pop_from_stack(t_mem **mem, t_stack *stack)
{
	if (!stack->length)
		error_exit(mem, EMPTY_STACK);
	--stack->length;
	return (stack->data[stack->length]);
}

int		top_of_stack(t_mem **mem, t_stack *stack)
{
	if (!stack->length)
		error_exit(mem, EMPTY_STACK);
	return (stack->data[stack->length - 1]);
}

int		sec_of_stack(t_mem **mem, t_stack *stack)
{
	if (stack->length < 2)
		error_exit(mem, NOT_ENOUGH_ELEM);
	return (stack->data[stack->length - 2]);
}

int		bot_of_stack(t_mem **mem, t_stack *stack)
{
	if (!stack->length)
		error_exit(mem, EMPTY_STACK);
	return (stack->data[0]);
}
