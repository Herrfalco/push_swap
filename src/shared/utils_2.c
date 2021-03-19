/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:46:10 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 13:45:52 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

static size_t	int_size(unsigned int nb)
{
	size_t	size;

	size = 1;
	while (nb /= 10)
		++size;
	return (size);
}

static void		rec_itoa(char *str, unsigned int nb)
{
	if (nb / 10)
		rec_itoa(str - 1, nb / 10);
	*str = nb % 10 + '0';
}

char			*my_itoa(t_glob *glob, int n)
{
	unsigned int	nb;
	int				minus;
	char			*str;
	char			*str_sav;
	size_t			nb_size;

	minus = n < 0 ? 1 : 0;
	nb = n < 0 ? n * -1 : n;
	nb_size = int_size(nb);
	str = mem_alloc(glob->mem, (nb_size + minus + 1) * sizeof(char));
	str_sav = str;
	if (minus)
		*str = '-';
	str[nb_size + minus] = '\0';
	rec_itoa(&(str[nb_size + minus - 1]), nb);
	return (str_sav);
}
