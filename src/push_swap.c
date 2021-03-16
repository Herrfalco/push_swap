/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:14 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 22:12:49 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	main(int argc, char **argv)
{
	t_glob		glob;
	t_stack		*result[RESULTS_NB];
	size_t		i;
	size_t		min;
	size_t		min_i;

	glob_init(&glob, argc, argv);
	i = 0;
	while (i < RESULTS_NB)
	{
		result[i] = NULL;
		++i;
	}
	bubble_sort(&glob, &result[0]);
	insertion_sort(&glob, &result[1]);
	back_track(&glob, &result[2]);
	min = result[0]->length;
	min_i = 0;
	i = 1;
	while (i < RESULTS_NB)
	{
		if (result[i] && result[i]->length < min)
		{
			min = result[i]->length;
			min_i = i;
		}
		++i;
	}
	print_op_stack(&glob, result[min_i]);
	glob_free(&glob);
	return (0);
}
