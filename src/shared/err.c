/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:59 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 11:42:50 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

void	error_exit(t_mem **mem, t_err error)
{
	if (mem && *mem)
		mem_free_all(mem);
	free(mem);
	write(2, "Error\n", 6);
	exit(error);
}
