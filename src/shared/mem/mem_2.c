/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:39:06 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 11:41:50 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

static void	mem_free(t_mem **mem, t_mem **mem_2_3)
{
	t_mem *next;

	if (!mem || !mem_2_3 || !*mem_2_3)
		error_exit(mem, FREE_ERR);
	next = (*mem_2_3)->next;
	free((*mem_2_3)->ptr);
	free(*mem_2_3);
	*mem_2_3 = next;
}

static void	rec_mem_free_all(t_mem **mem, t_mem **mem_2_3)
{
	if ((*mem_2_3)->next)
		rec_mem_free_all(mem, &(*mem_2_3)->next);
	mem_free(mem, mem_2_3);
}

void		mem_free_all(t_mem **mem)
{
	if (!mem)
		error_exit(mem, FREE_ALL_ERR);
	if (*mem)
		rec_mem_free_all(mem, mem);
}

void		mem_free_ptr(t_mem **mem, void *ptr)
{
	t_mem **base;

	base = mem;
	if (!mem || !*mem || !ptr)
		error_exit(base, FREE_PTR_ERR_1);
	while (*mem)
	{
		if ((*mem)->ptr == ptr)
		{
			mem_free(base, mem);
			return ;
		}
		mem = &(*mem)->next;
	}
	error_exit(base, FREE_PTR_ERR_2);
}
