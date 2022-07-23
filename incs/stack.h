/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:36 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 21:35:20 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_double_linked_node
{
	int							value;
	struct s_double_linked_node	*next;
	struct s_double_linked_node	*prev;
}	t_double_linked_node;

typedef t_double_linked_node	t_node;

typedef struct s_stack
{
	size_t	len;
	t_node	*top;
}	t_stack;

typedef	top->prev				t_bot;

typedef top->value				t_1st;
typedef top->next->value		t_2nd;
typedef top->next->next->value	t_3rd;
typedef t_bot->value			t_last;

// stack1.c
int		init_stack(t_stack *stack);
int		clear_stack(t_stack *stack);
int		push_node(t_stack *stack, t_node *node);
int		pop_node(t_stack *stack, t_node **node_ptr);
int		swap(t_stack *stack);

// stack2.c
int		push_value(t_stack *stack, int value);
int		pop_value(t_stack *stack, int *value_ptr);
int		rotate(t_stack *stack);
int		reverse_rotate(t_stack *stack);
int		to_array(t_stack *stack, int **array_ptr);

#endif