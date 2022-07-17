/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:54:25 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/15 23:08:28 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push_node(t_stack *stack, t_node *node)
{
	if (stack->len == 0)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		node->next->prev = node;
		node->prev->next = node;
	}
	stack->top = node;
	stack->len++;
	return (0);
}

int	pop_node(t_stack *stack, t_node **node_ptr)
{
	t_node	*node;

	if (stack->len == 0)
		return (-1);
	node = stack->top;
	if (stack->len == 1)
		stack->top = NULL;
	else
	{
		stack->top->next->prev = stack->top->prev;
		stack->top->prev->next = stack->top->next;
		stack->top = stack->top->next;
	}
	if (!node_ptr)
		free(node);
	else
	{
		node->next = NULL;
		node->prev = NULL;
		*node_ptr = node;
	}
	stack->len--;
	return (0);
}

int	push_value(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(t_node);
	if (!node)
		return (-1);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (push_node(stack, node));
}

int	pop_value(t_stack *stack, int *value_ptr)
{
	t_node	*node;

	if (pop_node(stack, &node) < 0)
		return (-1);
	*value_ptr = node->vlaue;
	free(node);
	return (0);
}
