/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:18 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 13:44:34 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

void	swap(t_stack *stack)
{
	void *tmp;

	if (stack->length < 2)
		return ;
	tmp = stack->data[stack->length - 1];
	stack->data[stack->length - 1] = stack->data[stack->length - 2];
	stack->data[stack->length - 2] = tmp;
}

void	push(t_mem **mem, t_stack *s1, t_stack *s2)
{
	if (s1->length < 1)
		return ;
	push_to_stack(mem, s2, pop_from_stack(mem, s1));
}

void	rotate(t_stack *stack)
{
	void	*tmp;
	size_t	len;

	if ((len = stack->length) < 2)
		return ;
	tmp = stack->data[len - 1];
	while (--len > 0)
		stack->data[len] = stack->data[len - 1];
	stack->data[0] = tmp;
}

void	rev_rotate(t_stack *stack)
{
	void	*tmp;
	size_t	i;

	if (stack->length < 2)
		return ;
	tmp = stack->data[0];
	i = -1;
	while (++i < stack->length - 1)
		stack->data[i] = stack->data[i + 1];
	stack->data[i] = tmp;
}
