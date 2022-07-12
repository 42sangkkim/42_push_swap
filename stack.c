/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:50:14 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 15:03:01 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

t_stack	new_stack(void)
{
	t_stack	stack;

	stack.len = 0;
	stack.top = NULL;
	return (stack);
}

void	destroy_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (stack->len)
		pop(stack, NULL);
}

int	push(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (-1);
	node->value = value;
	if (stack->len > 0)
	{
		node->prev = stack->top->prev;
		node->next = stack->top;
		stack->top->prev->next = node;
		stack->top->prev = node;
	}
	else
	{
		node->next = node;
		node->prev = node;
	}
	stack->len++;
	stack->top = node;
	return (0);
}

int	pop(t_stack *stack, int *value)
{
	t_node	*old_top;

	if (stack->len == 0)
		return (-1);
	else if (stack->len == 1)
	{
		if (value)
			*value = stack->top->value;
		free(stack->top);
		stack->top = NULL;
	}
	else
	{
		old_top = stack->top;
		if (value)
			*value = old_top->value;
		old_top->prev->next = old_top->next;
		old_top->next->prev = old_top->prev;
		stack->top = old_top->next;
		free(old_top);
	}
	stack->len--;
	return (0);
}

int	*to_array(t_stack *stack)
{
	int		*array;
	size_t	i;
	t_node	*node;

	array = malloc(stack->len * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	node = stack->top;
	while (i < stack->len)
	{
		array[i++] = node->value;
		node = node->next;
	}
	return (array);
}
