/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:08 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 11:41:52 by fcadet           ###   ########.fr       */
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

/*
**void *failoc(size_t size) {
**	static int success_nb = 8;
**
**	if (success_nb) {
**		success_nb--;
**		return malloc(size);
**	}
**	return NULL;
**}
**
**int main(void) {
**	t_mem *mem = mem_new();
**
**	if (!mem) {
**		error_exit(NULL, MEM_INIT);
**	}
**
**	void *p1 = mem_alloc(&mem, 10);
**	void *p2 = mem_alloc(&mem, 10);
**	void *p3 = mem_alloc(&mem, 10);
**	void *p4 = mem_alloc(&mem, 10);
**
**	print_mem(&mem);
**
**	mem_free_ptr(&mem, p1, TRUE);
**	mem_free_ptr(&mem, p3, FALSE);
**	mem_free_ptr(&mem, p2, TRUE);
**	mem_free_ptr(&mem, p4, FALSE);
**
**	print_mem(&mem);
**
**	p1 = mem_alloc(&mem, 10);
**	p2 = mem_alloc(&mem, 10);
**	p3 = mem_alloc(&mem, 10);
**	p4 = mem_alloc(&mem, 10);
**
**	mem_free_all(&mem, FALSE);
**
**	print_mem(&mem);
**
**	p1 = mem_alloc(&mem, 10);
**	p2 = mem_alloc(&mem, 10);
**	p3 = mem_alloc(&mem, 10);
**	p4 = mem_alloc(&mem, 10);
**
**	mem_free_all(&mem, TRUE);
**
**	print_mem(&mem);
**}
*/
