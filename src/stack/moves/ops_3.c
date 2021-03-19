/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:54:33 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 14:45:01 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

void	rrr(t_glob *glob, t_2_stacks *stacks)
{
	(void)glob;
	rev_rotate(stacks->a);
	rev_rotate(stacks->b);
}
