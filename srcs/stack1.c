/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:30:28 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 19:12:58 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	init_stack(t_stack *stack)
{
	stack->len = 0;
	stack->top = NULL;
	return (1);
}

int	clear_stack(t_stack *stack)
{
	t_node	*node;

	while (pop_node(stack, &node))
		free(node);
	return (1);
}

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
	return (1);
}

int	pop_node(t_stack *stack, t_node **node_ptr)
{
	*node_ptr = NULL;
	if (stack->len == 0)
		return (0);
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
	return (1);
}

int	swap(t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
		return (0);
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
	return (1);
}
