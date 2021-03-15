#include "../includes/includes.h"

void comp_sort(glob_t *glob, stack_t **result) {
	glob_t	*new_glob = glob_cpy(glob);

	(void)result;

	glob_free_cpy(&new_glob);
}
