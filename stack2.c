/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:25:10 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/14 15:54:55 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	pop_node(t_stack *stack, t_node **node_p)
{
	if (stack->len == 0)
		return (-1);
	else if (stack->len == 1)
	{
		if (node_p != NULL)
			*node_p = stack->top;
		stack->top->next = NULL;
		stack->top->prev = NULL;
		stack->top = NULL;
		stack->len--;
		return (0);
	}
	else
	{
		if (node_p != NULL)
			*node_p = stack->top;
		stack->top->next->prev = stack->top->prev;
		stack->top->prev->next = stack->top->next;
		stack->top = stack->top->next;
		stack->len--;
		return (1);
	}
}

int	push_node(t_stack *stack, t_node *node)
{
	if (stack->len == 0)
	{
		node->next = node;
		node->prev = node;
		stack->top = node;
		stack->len++;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		node->next->prev = node;
		node->prev->next = node;
		stack->top = node;
		stack->len++;
	}
	return (1);
}

int	pop_value(t_stack *stack, int *value_p)
{
	t_node	*node;

	if (pop_node(stack, &node) < 0)
		return (-1);
	*value_p = node->value;
	free(node);
	if (stack->len == 0)
		return (0);
	else
		return (1);
}

int	push_value(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (-1);
	node->value = value;
	push_node(stack, node);
	return (1);
}
