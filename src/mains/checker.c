/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:56 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 12:03:47 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static void	exec_ops_end(t_glob *glob, t_stack *op_stack, ssize_t read_ret,
	size_t j)
{
	if (read_ret)
		error_exit(glob->mem, READ_ERR);
	if (j != 0)
		error_exit(glob->mem, OP_LINE_RET_ERR);
	exec_op_stack(glob, op_stack);
}

static void	exec_ops(t_glob *glob, t_stack *op_stack, char *buffer_read,
	char *buffer_op)
{
	ssize_t read_ret;
	ssize_t	i;
	size_t	j;

	j = 0;
	while ((read_ret = read(0, buffer_read, READ_BUFFER_SIZE)) > 0)
	{
		i = -1;
		while (++i < read_ret)
		{
			if (buffer_read[i] == '\n')
			{
				buffer_op[j] = '\0';
				add_to_op_stack(glob, op_stack, buffer_op);
				j = 0;
			}
			else if (j > 2)
				error_exit(glob->mem, OP_TOO_LONG);
			else
				buffer_op[j++] = buffer_read[i];
		}
	}
	exec_ops_end(glob, op_stack, read_ret, j);
}

int			main(int argc, char **argv)
{
	t_glob	glob;
	char	buffer_read[READ_BUFFER_SIZE];
	char	buffer_op[OP_BUFFER_SIZE];

	glob_init(&glob, argc, argv);
	if (argc > 1)
	{
		exec_ops(&glob, stack_new(glob.mem), buffer_read, buffer_op);
		write(1, (!stack_entropy(glob.a, ASCENDING) && !glob.b->length) ?
			"OK\n" : "KO\n", 3);
	}
	glob_free(&glob);
	return (0);
}
