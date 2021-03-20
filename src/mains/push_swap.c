/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:14 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/20 20:53:33 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int		main(int argc, char **argv)
{
	t_glob		glob;
	//t_2_stacks	*stacks_1;
	t_2_stacks	*stacks_2;
	//t_stack		*result_1;
	t_stack		*result_2;

	glob_init(&glob);
	//stacks_1 = stacks_init(glob.mem, argc, argv);
	//result_1 = custom_sort(&glob, stacks_1);
	stacks_2 = stacks_init(glob.mem, argc, argv);
	result_2 = optimised_sort(&glob, stacks_2);
	//display_stack(&glob, result_1);
	display_stack(&glob, result_2);
	glob_free(&glob);
	return (0);
}
