/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:12:29 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 01:26:59 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	swap(t_stack *stack)
{
	int	tmp_val;

	if (stack->len >= 2)
	{
		tmp_val = stack->top->value;
		stack->top->value = stack->top->next->value;
		stack->top->next->value = tmp_val;
	}
	return (0);
}

int	rotate(t_stack *stack)
{
	if (stack->len > 0)
		stack->top = stack->top->next;
	return (0);
}

int	r_rotate(t_stack *stack)
{
	if (stack->len > 0)
		stack->top = stack->top->prev;
	return (0);
}
