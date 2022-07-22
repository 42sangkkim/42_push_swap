/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:59:21 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 21:04:32 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack *stack)
{
	int	value;

	if (stack->len < 2)
		return (0);
	else
	{
		value = stack->top->value;
		stack->top->value = stack->top->next->value;
		stack->top->next->value = value;
		return (1);
	}
}

int	sa(t_push_swap *push_swap)
{
	if (swap(&(push_swap->a)))
		return (1);
	return (0);
}

int	sb(t_push_swap *push_swap)
{
	if (swap(&(push_swap->b)))
		return (1);
	return (0);
}

int	ss(t_push_swap *push_swap)
{
	if (swap(&(push_swap->a)) + swap(&(push_swap->b)))
		return (1);
	return (0);
}
