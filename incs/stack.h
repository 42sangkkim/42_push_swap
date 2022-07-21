/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:47:08 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/19 16:12:16 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	size_t	len;
	t_node	*top;
}	t_stack;

int		init_stack(t_stack *stack);
int		destroy_stack(t_stack *stack);
int		push_node(t_stack *stack, t_node *node);
int		pop_node(t_stack *stack, t_node **node_ptr);
int		push_value(t_stack *stack, int value);
int		pop_value(t_stack *stack, int *value_ptr);
int		rotate(t_stack *stack);
int		reverse_rotate(t_stack *stack);

int		swap(t_stack *stack);
int		is_sorted(t_stack *stack, size_t n);
int		is_rev_sorted(t_stack *stack, size_t n);
int		to_array(t_stack *stack, int **array_ptr);
int		print_stack(t_stack *stack);

#endif
