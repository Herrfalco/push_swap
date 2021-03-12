#ifndef HEADERS_H
# define HEADERS_H

mem_t *mem_new(void);
void mem_free_all(mem_t **mem, bool_t destroy);
void mem_free_ptr(mem_t **mem, void *ptr, bool_t destroy);
void *mem_alloc(mem_t **mem, size_t size);

void error_exit(mem_t **, err_t);

long my_atoi(const char *str);

stack_t *stack_new(mem_t **mem);
stack_t *stack_from_args(mem_t **mem, int argc, char **argv);
void push_to_stack(mem_t **mem, stack_t *stack, int val);
int pop_from_stack(stack_t *stack);

void swap(stack_t *stack);
void push(mem_t **mem, stack_t *s1, stack_t *s2);
void rotate(stack_t *stack);
void rev_rotate(stack_t *stack);

#endif
