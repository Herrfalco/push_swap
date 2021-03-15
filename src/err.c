#include "../includes/includes.h"

void error_exit(mem_t **mem, err_t error) {
	if (mem && *mem)
		mem_free_all(mem);
	free(mem);
	write(2, "Error\n", 6);
	exit(error);
}
