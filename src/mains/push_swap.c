/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:14 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 12:33:23 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

size_t	find_best_sort(t_stack **results)
{
	size_t		min;
	size_t		min_i;
	size_t		i;

	min = results[0]->length;
	min_i = 0;
	i = 0;
	while (++i < RESULTS_NB)
	{
		if (results[i] && results[i]->length < min)
		{
			min = results[i]->length;
			min_i = i;
		}
	}
	return (min_i);
}

int		main(int argc, char **argv)
{
	t_glob		glob;
	t_stack		*results[RESULTS_NB];
	size_t		i;

	glob_init(&glob, argc, argv);
	i = -1;
	while (++i < RESULTS_NB)
		results[i] = NULL;
	bubble_sort(&glob, &results[0]);
	insertion_sort(&glob, &results[1]);
	back_track(&glob, &results[2]);
	write(1, "\nbubble:\n", 9);
	print_op_stack(&glob, results[0]);
	write(1, "\ninsertion:\n", 12);
	print_op_stack(&glob, results[1]);
	write(1, "\nback track:\n", 13);
	print_op_stack(&glob, results[2]);
	write(1, "\nbest:\n", 7);
	print_op_stack(&glob, results[find_best_sort(results)]);
	glob_free(&glob);
	return (0);
}
