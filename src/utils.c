#include "../includes/includes.h"

long my_atoi(const char *str) {
	long	result = 0;
	int		sign;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' ||
		*str == '\v' || *str == '\f')
		str++;
	sign = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+') {
		str++;
		if (*str < '0' || *str > '9')
			return ATOI_ERR_RET;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return ATOI_ERR_RET;
		result *= 10;
		result += *str - '0';
		if ((result * sign > INT_MAX_ABS) || (result * sign < INT_MIN_ABS))
			return ATOI_ERR_RET;
		str++;
	}
	result *= sign;
	return (result);
}

ssize_t str_cmp(const char *s1, const char *s2) {
	while (*s1 == *s2 && *s1) {
		++s1;
		++s2;
	}
	return (*s2 - *s1);
}

size_t	str_len(const char *s) {
	size_t	len = -1;

	while (s[++len]);
	return len;
}

char	*str_cpy(mem_t **mem, const char *s) {
	size_t	i;
	size_t	s_size = str_len(s) + 1;
	char	*cpy = mem_alloc(mem, s_size);

	for (i = 0; i < s_size; ++i) {
		cpy[i] = s[i];
	}
	return (cpy);
}
