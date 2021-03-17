/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:36 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/17 23:13:24 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

/*
** Memory
*/
t_mem	*mem_new(void);
void	mem_free_all(t_mem **mem);
void	mem_free_ptr(t_mem **mem, void *ptr);
void	*mem_alloc(t_mem **mem, size_t size);

/*
** Errors
*/
void	error_exit(t_mem **mem, t_err error);

/*
** Utils
*/
long	my_atoi(char *str);
ssize_t	str_cmp(const char *s1, const char *s2);
size_t	str_len(const char *s);
char	*str_cpy(t_mem **mem, const char *s);

/*
** Stack
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
** Stack basic operations
*/
t_bool	swap(t_stack *stack);
t_bool	push(t_mem **mem, t_stack *s1, t_stack *s2);
t_bool	rotate(t_stack *stack);
t_bool	rev_rotate(t_stack *stack);

/*
** "Global" variables
*/
void	glob_init(t_glob *glob, int argc, char **argv);
t_glob	*glob_cpy(t_glob *glob);
void	glob_free_cpy(t_glob **glob);
void	glob_free(t_glob *glob);

/*
** Operations stack
*/
void	print_op_stack(t_glob *glob, t_stack *op_stack);
void	add_to_op_stack(t_glob *glob, t_stack *op_stack, char *id);
void	exec_op_stack(t_glob *glob, t_stack *op_stack);

/*
** Operations implementation
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
** Functions shared between sorts
*/
t_bool	sorted(t_glob *glob);
void	stack_concat(t_glob *glob, t_stack *result);
void	stack_push_exec(t_glob *glob, t_stack *result, t_op_enum op);
void	stack_double_push_exec(t_glob *glob, t_stack *result, t_op_enum op_1,
	t_op_enum op_2);
size_t	stack_entropy(t_stack *stack, t_order order);

/*
** Sorts
*/
void	back_track(t_glob *glob, t_stack **result);
void	bubble_sort(t_glob *glob, t_stack **result);
void	insertion_sort(t_glob *glob, t_stack **result);

/*
** Debug
**
**void	print_stacks(t_glob *glob);
**void	print_mem(t_mem **mem);
**void	print_ptr(void *ptr);
*/

#endif
