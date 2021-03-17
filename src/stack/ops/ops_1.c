/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:10 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 23:05:54 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/includes.h"

t_bool	sa(t_glob *glob)
{
	return (swap(glob->a));
}

t_bool	sb(t_glob *glob)
{
	return (swap(glob->b));
}

t_bool	ss(t_glob *glob)
{
	t_bool	ret_a;
	t_bool	ret_b;

	ret_a = swap(glob->a);
	ret_b = swap(glob->b);
	return (ret_a == FALSE ? ret_b : TRUE);
}

t_bool	pa(t_glob *glob)
{
	return (push(glob->mem, glob->b, glob->a));
}

t_bool	pb(t_glob *glob)
{
	return (push(glob->mem, glob->a, glob->b));
}
