/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:08 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 22:35:50 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

t_mem		*mem_new(void)
{
	t_mem *mem;

	mem = malloc(sizeof(t_mem));
	if (!mem)
		return (NULL);
	mem->ptr = NULL;
	mem->next = NULL;
	return (mem);
}

void		*mem_alloc(t_mem **mem, size_t size)
{
	t_mem *new_ptr;

	new_ptr = NULL;
	if (!mem)
		error_exit(mem, ALLOC_ERR_1);
	if (!(new_ptr = mem_new()))
		error_exit(mem, ALLOC_ERR_2);
	if (!(new_ptr->ptr = malloc(size)))
		error_exit(mem, ALLOC_ERR_3);
	new_ptr->next = *mem;
	*mem = new_ptr;
	return (new_ptr->ptr);
}
