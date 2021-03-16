/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:36 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 22:22:52 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

/*
** mem.c
*/
t_mem	*mem_new(void);
void	mem_free_all(t_mem **mem);
void	mem_free_ptr(t_mem **mem, void *ptr);
void	*mem_alloc(t_mem **mem, size_t size);

/*
**error.c
*/
void	error_exit(t_mem **mem, t_err error);

/*
**utils.c
*/
long	my_atoi(const char *str);
ssize_t	str_cmp(const char *s1, const char *s2);
size_t	str_len(const char *s);
char	*str_cpy(t_mem **mem, const char *s);

/*
**stack.c
*/
t_stack	*stack_new(t_mem **mem);
t_stack	*stack_from_args(t_mem **mem, int argc, char **argv);
t_stack	*stack_cpy(t_mem **mem, t_stack *stack);
void	push_to_stack(t_mem **mem, t_stack *stack, int val);
int		pop_from_stack(t_mem **mem, t_stack *stack);
int		top_of_stack(t_mem **mem, t_stack *stack);
int		sec_of_stack(t_mem **mem, t_stack *stack);
int		bot_of_stack(t_mem **mem, t_stack *stack);
void	stack_free(t_mem **mem, t_stack **stack);

/*
**stack_ops.c
*/
t_bool	swap(t_stack *stack);
t_bool	push(t_mem **mem, t_stack *s1, t_stack *s2);
t_bool	rotate(t_stack *stack);
t_bool	rev_rotate(t_stack *stack);

/*
**global.c
*/
void	glob_init(t_glob *glob, int argc, char **argv);
t_glob	*glob_cpy(t_glob *glob);
void	glob_free_cpy(t_glob **glob);
void	glob_free(t_glob *glob);

/*
**op_stack.c
*/
void	print_op_stack(t_glob *glob, t_stack *op_stack);
void	add_to_op_stack(t_glob *glob, t_stack *op_stack, char *id);
void	exec_op_stack(t_glob *glob, t_stack *op_stack);

/*
**ops\*.c
*/
t_bool	sa(t_glob *glob);
t_bool	sb(t_glob *glob);
t_bool	ss(t_glob *glob);
t_bool	pa(t_glob *glob);
t_bool	pb(t_glob *glob);
t_bool	ra(t_glob *glob);
t_bool	rb(t_glob *glob);
t_bool	rr(t_glob *glob);
t_bool	rra(t_glob *glob);
t_bool	rrb(t_glob *glob);
t_bool	rrr(t_glob *glob);

/*
**shared.c
*/
t_bool	sorted(t_glob *glob);
void	stack_concat(t_glob *glob, t_stack *result);
void	stack_push_exec(t_glob *glob, t_stack *result, t_op_enum op);
size_t	stack_entropy(t_stack *stack, t_order order);

/*
**sorts\*.c
*/
void	back_track(t_glob *glob, t_stack **result);
void	bubble_sort(t_glob *glob, t_stack **result);
void	insertion_sort(t_glob *glob, t_stack **result);

/*
**debug.c
*/
void	print_stacks(t_glob *glob);
void	print_mem(t_mem **mem);
void	print_ptr(void *ptr);

#endif
