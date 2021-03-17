/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:54:07 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 23:05:11 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

t_bool	ra(t_glob *glob)
{
	return (rotate(glob->a));
}

t_bool	rb(t_glob *glob)
{
	return (rotate(glob->b));
}

t_bool	rr(t_glob *glob)
{
	t_bool	ret_a;
	t_bool	ret_b;

	ret_a = rotate(glob->a);
	ret_b = rotate(glob->b);
	return (ret_a == FALSE ? ret_b : TRUE);
}

t_bool	rra(t_glob *glob)
{
	return (rev_rotate(glob->a));
}

t_bool	rrb(t_glob *glob)
{
	return (rev_rotate(glob->b));
}
