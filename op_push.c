/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:41:19 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/14 13:47:28 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

void	op_pa(t_stack *a, t_stack *b, size_t n)
{
	t_node	*tmp;

	if (n > b->len)
		n = b->len;
	while (n--)
	{
		write(1, " pa_start ", 10);
		tmp = pop_node(b);
		write(1, " pop ", 5);
		push_node(a, tmp);
		write(1, "pa\n", 3);
	}
	write(1, "pa end\n", 7);
}

void	op_pb(t_stack *a, t_stack *b, size_t n)
{
	t_node	*tmp;

	if (n > a->len)
		n = a->len;
	while (n--)
	{
		write(1, " pb_start ", 10);
		tmp = pop_node(a);
		write(1, " pop ", 5);
		push_node(b, tmp);
		write(1, "pb\n", 3);
	}
}

t_node	*pop_node(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (stack->len == 1)
		stack->top = NULL;
	else
	{
		stack->top->next->prev = stack->top->prev;
		stack->top->prev->next = stack->top->next;
		stack->top = stack->top->next;
	}
	tmp->next = tmp;
	tmp->prev = tmp;
	stack->len--;
	return (tmp);
}

void	push_node(t_stack *stack, t_node *node)
{
	if (stack->len == 0)
		stack->top = node;
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->next->prev = node;
		stack->top->prev->next = node;
	}
	stack->top = node;
	stack->len++;
}
