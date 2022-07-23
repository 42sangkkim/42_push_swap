/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:59:05 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 20:46:09 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push_value(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (0);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (push_node(stack, node));
}

int	pop_value(t_stack *stack, int *value_ptr)
{
	t_node	*node;

	*value_ptr = 0;
	if (!pop_node(stack, &node))
		return (0);
	*value_ptr = node->value;
	free(node);
	return (1);
}

int	rotate(t_stack *stack)
{
	if (stack->len < 2)
		return (0);
	stack->top = stack->top->next;
	return (1);
}

int	reverse_rotate(t_stack *stack)
{
	if (stack->len < 2)
		return (0);
	stack->top = stack->top->prev;
	return (1);
}

int	to_array(t_stack *stack, int **array_ptr)
{
	size_t	i;
	t_node	*node;
	int		*array;

	if (stack->len == 0)
		return (0);
	array = malloc(stack->len * sizeof(int));
	if (!array)
		return (-1);
	i = 0;
	node = stack->top;
	while (i < stack->len)
	{
		array[i] = node->value;
		node = node->next;
	}
	*array_ptr = array;
	return (1);
}
