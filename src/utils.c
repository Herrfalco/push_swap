/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:20 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 20:33:00 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

long	my_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' ||
		*str == '\v' || *str == '\f')
		str++;
	sign = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
	{
		str++;
		if (*str < '0' || *str > '9')
			return (ATOI_ERR_RET);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (ATOI_ERR_RET);
		result *= 10;
		result += *str - '0';
		if ((result * sign > INT_MAX_ABS) || (result * sign < INT_MIN_ABS))
			return (ATOI_ERR_RET);
		str++;
	}
	result *= sign;
	return (result);
}

ssize_t	str_cmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s2 - *s1);
}

size_t	str_len(const char *s)
{
	size_t	len;

	len = -1;
	while (s[++len])
		;
	return (len);
}

char	*str_cpy(t_mem **mem, const char *s)
{
	size_t	i;
	size_t	s_size;
	char	*cpy;

	s_size = str_len(s) + 1;
	cpy = mem_alloc(mem, s_size);
	i = 0;
	while (i < s_size)
	{
		cpy[i] = s[i];
		++i;
	}
	return (cpy);
}
