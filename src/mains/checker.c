/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:56 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 15:59:11 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static void	exec_ops_end(t_glob *glob, t_stack *op_stack, ssize_t err, t_2_stacks *stacks)
{
	if (err < 0)
		error_exit(glob->mem, READ_ERR);
	if (err > 0)
		error_exit(glob->mem, OP_LINE_RET_ERR);
	exec_op_stack(glob, op_stack, stacks);
}

static void	exec_ops(t_glob *glob, t_2_stacks *stacks, t_stack *op_stack)
{
	char	buffer_read[READ_BUFFER_SIZE];
	char	buffer_op[OP_BUFFER_SIZE];
	ssize_t read_ret;
	ssize_t	i;
	ssize_t	j;

	j = 0;
	while ((read_ret = read(0, buffer_read, READ_BUFFER_SIZE)) > 0)
	{
		i = -1;
		while (++i < read_ret)
		{
			if (buffer_read[i] == '\n')
			{
				buffer_op[j] = '\0';
				push_op_to_stack(glob, op_stack, buffer_op);
				j = 0;
			}
			else if (j > 2)
				error_exit(glob->mem, OP_TOO_LONG);
			else
				buffer_op[j++] = buffer_read[i];
		}
	}
	exec_ops_end(glob, op_stack, read_ret < 0 ? -1 : j, stacks);
}

int			main(int argc, char **argv)
{
	t_glob		glob;
	t_2_stacks	*stacks;

	glob_init(&glob);
	stacks = stacks_init(glob.mem, argc, argv);
	if (argc > 1)
	{
		exec_ops(&glob, stacks, stack_new(glob.mem, OPERATION));
		write(1, (!stack_entropy(stacks->a, ASCENDING) && !stacks->b->length) ?
			"OK\n" : "KO\n", 3);
	}
	glob_free(&glob);
	return (0);
}
