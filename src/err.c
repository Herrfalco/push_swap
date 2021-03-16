/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:59 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 17:33:00 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void error_exit(mem_t **mem, err_t error) {
	if (mem && *mem)
		mem_free_all(mem);
	free(mem);
	write(2, "Error\n", 6);
	exit(error);
}
