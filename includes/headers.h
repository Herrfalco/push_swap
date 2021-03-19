/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:56:45 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/19 22:34:55 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

/*
** Memory
*/
t_mem		*mem_new(void);
void		*mem_alloc(t_mem **mem, size_t size);
void		mem_free_all(t_mem **mem);
void		mem_free_ptr(t_mem **mem, void *ptr);

/*
** Errors
*/
void		error_exit(t_mem **mem, t_err error);

/*
** Utils
*/
long		my_atoi(char *str);
ssize_t		str_cmp(const char *s1, const char *s2);
size_t		str_len(const char *s);
char		*str_cpy(t_mem **mem, const char *s);
char		*my_itoa(t_glob *glob, int n);

/*
** Stack
*/
t_stack		*stack_new(t_mem **mem, t_type type);
void		push_to_stack(t_mem **mem, t_stack *stack, void *val);
void		*pop_from_stack(t_mem **mem, t_stack *stack);
void		display_stack(t_glob *glob, t_stack *stack);

/*
** Specialized stacks
*/
void		push_op_to_stack(t_glob *glob, t_stack *stack, char *str);
void		exec_op_stack(t_glob *glob, t_stack *op_stack, t_2_stacks *stacks);
t_2_stacks	*stacks_init(t_mem **mem, int argc, char **argv);

/*
** Operations implementation
*/
void		swap(t_stack *stack);
void		push(t_mem **mem, t_stack *s1, t_stack *s2);
void		rotate(t_stack *stack);
void		rev_rotate(t_stack *stack);

void		sa(t_glob *glob, t_2_stacks *stacks);
void		sb(t_glob *glob, t_2_stacks *stacks);
void		ss(t_glob *glob, t_2_stacks *stacks);
void		pa(t_glob *glob, t_2_stacks *stacks);
void		pb(t_glob *glob, t_2_stacks *stacks);
void		ra(t_glob *glob, t_2_stacks *stacks);
void		rb(t_glob *glob, t_2_stacks *stacks);
void		rr(t_glob *glob, t_2_stacks *stacks);
void		rra(t_glob *glob, t_2_stacks *stacks);
void		rrb(t_glob *glob, t_2_stacks *stacks);
void		rrr(t_glob *glob, t_2_stacks *stacks);

/*
** "Global" variables
*/
void		glob_init(t_glob *glob);
void		glob_free(t_glob *glob);

/*
** Functions shared between sorts
*/
t_bool		sorted(t_2_stacks *stacks);
void		stacks_concat(t_glob *glob, t_2_stacks *stacks,
	t_stack *result);
void		stack_push_exec(t_glob *glob, t_2_stacks *stacks,
	t_stack *result, t_op op);
size_t		stack_entropy(t_stack *stack, t_order order);

/*
** Sorts
*/
t_stack		*insertion_sort(t_glob *glob, t_2_stacks *stacks);

#endif
