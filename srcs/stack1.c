/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:52:11 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/15 22:54:19 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	init_stack(t_stack *stack)
{
	stack->len = 0;
	stack->top = NULL;
	return (0);
}

int	destroy_stack(t_stack *stack)
{
	while (stack->len)
	{
		if (pop_node(stack, NULL) < 0)
			return (-1);
	}
	return (0);
}

int	rotate(t_stack *stack)
{
	if (stack->len <= 1)
		return (0);
	else
	{
		stack->top = stack->top->next;
		return (1);
	}
}

int	reverse_rotate(t_stack *stack)
{
	if (stack->len <= 1)
		return (0);
	else
	{
		stack->top = stack->top->prev;
		return (1);
	}
}