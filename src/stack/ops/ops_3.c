/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:54:33 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 23:04:28 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

t_bool	rrr(t_glob *glob)
{
	t_bool	ret_a;
	t_bool	ret_b;

	ret_a = rev_rotate(glob->a);
	ret_b = rev_rotate(glob->b);
	return (ret_a == FALSE ? ret_b : TRUE);
}
