/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <fcadet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:33:17 by fcadet            #+#    #+#             */
/*   Updated: 2021/03/16 17:33:18 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

stack_t *stack_new(mem_t **mem) {
	stack_t *stack = mem_alloc(mem, sizeof(stack_t));

	stack->length = 0;		
	stack->capacity = 0;
	stack->data = NULL;
	return (stack);
}

stack_t *stack_from_args(mem_t **mem, int argc, char **argv) {
	int		i;
	long	val;
	stack_t *stack = stack_new(mem);
	size_t	j;

	--argc;
	for (i = argc; i > 0; --i) {
		if ((val = my_atoi(argv[i])) == ATOI_ERR_RET)
			error_exit(mem, ATOI_ERR);
		for (j = 0; j < stack->length; ++j) {
			if (stack->data[j] == (int)val) {
				error_exit(mem, DUPLICATES_ERR);
			}
		}
		push_to_stack(mem, stack, (int)val);
	}
	return (stack);
}

stack_t *stack_cpy(mem_t **mem, stack_t *stack) {
	stack_t *new_stack = stack_new(mem);
	size_t	i;

	new_stack->length = stack->length;
	new_stack->capacity = stack->capacity;
	new_stack->data = mem_alloc(mem, sizeof(int) * stack->capacity);
	for (i = 0; i < stack->length; ++i) {
		new_stack->data[i] = stack->data[i];
	}
	return (new_stack);
}

void push_to_stack(mem_t **mem, stack_t *stack, int val) {
	int *new_data;
	size_t i;

	if (stack->length + 1 > stack->capacity) {
		stack->capacity = stack->capacity ? stack->capacity * 2 : 1;
		new_data = mem_alloc(mem, stack->capacity * sizeof(int));
		if (stack->data) {
			for (i = 0; i < stack->length; ++i)
				new_data[i] = stack->data[i];
			mem_free_ptr(mem, stack->data);
		}
		stack->data = new_data;
	}
	stack->data[stack->length++] = val;
}

int pop_from_stack(mem_t **mem, stack_t *stack) {
	if (!stack->length)
		error_exit(mem, EMPTY_STACK);
	--stack->length;
	return (stack->data[stack->length]);
}

int top_of_stack(mem_t **mem, stack_t *stack) {
	if (!stack->length)
		error_exit(mem, EMPTY_STACK);
	return (stack->data[stack->length - 1]);
}

int sec_of_stack(mem_t **mem, stack_t *stack) {
	if (stack->length < 2)
		error_exit(mem, NOT_ENOUGH_ELEM);
	return (stack->data[stack->length - 2]);
}

int bot_of_stack(mem_t **mem, stack_t *stack) {
	if (!stack->length)
		error_exit(mem, EMPTY_STACK);
	return (stack->data[0]);
}

void stack_free(mem_t **mem, stack_t **stack) {
	if ((*stack)->data) {
		mem_free_ptr(mem, (*stack)->data);
	}
	mem_free_ptr(mem, *stack);
	(*stack) = NULL;
}
