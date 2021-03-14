#ifndef HEADERS_H
# define HEADERS_H

mem_t *mem_new(void);
void mem_free_all(mem_t **mem, bool_t destroy);
void mem_free_ptr(mem_t **mem, void *ptr, bool_t destroy);
void *mem_alloc(mem_t **mem, size_t size);

void error_exit(mem_t **, err_t);

long	my_atoi(const char *str);
ssize_t	str_cmp(const char *s1, const char *s2);
size_t	str_len(const char *s);
char	*str_cpy(mem_t **mem, const char *s);

stack_t *stack_new(mem_t **mem);
stack_t *stack_from_args(mem_t **mem, int argc, char **argv);
void push_to_stack(mem_t **mem, stack_t *stack, int val);
int pop_from_stack(stack_t *stack);
size_t stack_entropy(stack_t *stack);

void swap(stack_t *stack);
void push(mem_t **mem, stack_t *s1, stack_t *s2);
void rotate(stack_t *stack);
void rev_rotate(stack_t *stack);

void glob_init(glob_t *glob, int argc, char **argv);
void glob_free(glob_t *glob);

void sa(glob_t*);
void sb(glob_t*);
void ss(glob_t*);
void pa(glob_t*);
void pb(glob_t*);
void ra(glob_t*);
void rb(glob_t*);
void rr(glob_t*);
void rra(glob_t*);
void rrb(glob_t*);
void rrr(glob_t*);

#endif
