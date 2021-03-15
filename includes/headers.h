#ifndef HEADERS_H
# define HEADERS_H

//mem.c
mem_t *mem_new(void);
void mem_free_all(mem_t **mem);
void mem_free_ptr(mem_t **mem, void *ptr);
void *mem_alloc(mem_t **mem, size_t size);

//error.c
void error_exit(mem_t **mem, err_t);

//utils.c
long	my_atoi(const char *str);
ssize_t	str_cmp(const char *s1, const char *s2);
size_t	str_len(const char *s);
char	*str_cpy(mem_t **mem, const char *s);

//stack.c
stack_t *stack_new(mem_t **mem);
stack_t *stack_from_args(mem_t **mem, int argc, char **argv);
stack_t *stack_cpy(mem_t **mem, stack_t *stack);
void push_to_stack(mem_t **mem, stack_t *stack, int val);
int pop_from_stack(mem_t **mem, stack_t *stack);
int top_of_stack(mem_t **mem, stack_t *stack);
int sec_of_stack(mem_t **mem, stack_t *stack);
int bot_of_stack(mem_t **mem, stack_t *stack);
void stack_free(mem_t **mem, stack_t **stack);

//stack_ops.c
bool_t swap(stack_t *stack);
bool_t push(mem_t **mem, stack_t *s1, stack_t *s2);
bool_t rotate(stack_t *stack);
bool_t rev_rotate(stack_t *stack);

//global.c
void	glob_init(glob_t *glob, int argc, char **argv);
glob_t	*glob_cpy(glob_t *glob);
void	glob_free_cpy(glob_t **glob);
void	glob_free(glob_t *glob);

//op_stack.c
void print_op_stack(glob_t *glob, stack_t *op_stack);
void add_to_op_stack(glob_t *glob, stack_t *op_stack, char *id);
void exec_op_stack(glob_t *glob, stack_t *op_stack);

//ops.c
bool_t sa(glob_t*);
bool_t sb(glob_t*);
bool_t ss(glob_t*);
bool_t pa(glob_t*);
bool_t pb(glob_t*);
bool_t ra(glob_t*);
bool_t rb(glob_t*);
bool_t rr(glob_t*);
bool_t rra(glob_t*);
bool_t rrb(glob_t*);
bool_t rrr(glob_t*);

//shared.c
size_t stack_entropy(stack_t *stack, order_t order);
bool_t	sorted(glob_t *glob);

//back_track.c
void back_track(glob_t *glob, stack_t **result);
//bubble.c
void bubble_sort(glob_t *glob, stack_t **result);
//insertion.c
void insertion_sort(glob_t *glob, stack_t **result);

//debug.c
void print_stacks(glob_t *glob);
void print_mem(mem_t **mem);
void print_ptr(void *ptr);

#endif
