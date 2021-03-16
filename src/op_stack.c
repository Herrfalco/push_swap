/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:12 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 18:04:46 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	print_op_stack(t_glob *glob, t_stack *op_stack)
{
	size_t	i;
	char	*op_str;

	i = 0;
	while (i < op_stack->length)
	{
		if (op_stack->data[i] < 0 || op_stack->data[i] >= OP_NUMBER)
			error_exit(glob->mem, OP_ID_ERR);
		op_str = glob->op_str[op_stack->data[i]];
		write(1, op_str, str_len(op_str));
		write(1, "\n", 1);
		++i;
	}
}

void	add_to_op_stack(t_glob *glob, t_stack *op_stack, char *id)
{
	size_t	i;

	i = 0;
	while (i < OP_NUMBER)
	{
		if (!str_cmp(id, glob->op_str[i]))
		{
			push_to_stack(glob->mem, op_stack, i);
			return ;
		}
		++i;
	}
	error_exit(glob->mem, OP_STR_ERR);
}

void	exec_op_stack(t_glob *glob, t_stack *op_stack)
{
	size_t i;

	i = 0;
	while (i < op_stack->length)
	{
		glob->op_fn[op_stack->data[i]](glob);
		++i;
	}
}
