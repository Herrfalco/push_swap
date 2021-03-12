#include "../includes/includes.h"

long my_atoi(const char *str)
{
	long	result = 0;
	int		sign;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' ||
		*str == '\v' || *str == '\f')
		str++;
	sign = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
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

/*
#include <stdio.h>

int main(int argc, char **argv) {
	int i;
	long result;

	for (i = 1; i < argc; ++i) {
		if ((result = ft_atoi(argv[i])) == ATOI_ERR_RET) {
			error_exit(NULL, ATOI_ERR);
		}
		printf("%d\n", (int)result);	
	}
	return (0);
}
*/
