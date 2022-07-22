/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:20:51 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 21:04:32 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack *stack)
{
	if (stack->len < 0)
		return (0);
	stack->top = stack->top->next;
	return (1);
}

int	ra(t_push_swap *push_swap)
{
	if (rotate(&(push_swap->a)))
		return (1);
	return (0);
}

int	rb(t_push_swap *push_swap)
{
	if (rotate(&(push_swap->b)))
		return (1);
	return (0);
}

int	rr(t_push_swap *push_swap)
{
	if (rotate(&(push_swap->a)) + rotate(&(push_swap->b)))
		return (1);
	return (0);
}
