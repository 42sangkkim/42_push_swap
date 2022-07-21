/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:30:28 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/21 22:03:34 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (stack->len == 0)
	{
		*node_ptr = NULL;
		return (-1);
	}
	*node_ptr = stack->top;
	if (stack->len == 1)
		stack->top = NULL;
	else
	{
		stack->top->next->prev = stack->top->prev;
		stack->top->prev->next = stack->top->next;
		stack->top = stack->top->next;
	}
	(*node_ptr)->next = NULL;
	(*node_ptr)->prev = NULL;
	stack->len--;
	return (0);
}

int	push_value(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (-1);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	push_node(stack, node);
	return (0);
}
