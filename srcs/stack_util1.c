/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:08:37 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/19 16:14:40 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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

int	is_sorted(t_stack *stack, size_t n)
{
	t_node	*node;

	if (stack->len < 2)
		return (1);
	node = stack->top;
	n--;
	while (n--)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	is_rev_sorted(t_stack *stack, size_t n)
{
	t_node	*node;

	if (stack->len < 2)
		return (1);
	node = stack->top;
	n--;
	while (n--)
	{
		if (node->value < node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
