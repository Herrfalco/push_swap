/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:18 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 20:28:52 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_bool	swap(t_stack *stack)
{
	int tmp;

	if (stack->length < 2)
		return (FALSE);
	tmp = stack->data[stack->length - 1];
	stack->data[stack->length - 1] = stack->data[stack->length - 2];
	stack->data[stack->length - 2] = tmp;
	return (TRUE);
}

t_bool	push(t_mem **mem, t_stack *s1, t_stack *s2)
{
	if (s1->length < 1)
		return (FALSE);
	push_to_stack(mem, s2, pop_from_stack(mem, s1));
	return (TRUE);
}

t_bool	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->length - 1;
	if (stack->length < 2)
		return (FALSE);
	tmp = stack->data[i];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		--i;
	}
	stack->data[0] = tmp;
	return (TRUE);
}

t_bool	rev_rotate(t_stack *stack)
{
	int		tmp;
	size_t	i;

	if (stack->length < 2)
		return (FALSE);
	tmp = stack->data[0];
	i = 0;
	while (i < stack->length - 1)
	{
		stack->data[i] = stack->data[i + 1];
		++i;
	}
	stack->data[i] = tmp;
	return (TRUE);
}
