/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:20:51 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/21 21:45:25 by sangkkim         ###   ########seoul.kr  */
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
	{
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	rb(t_push_swap *push_swap)
{
	if (rotate(&(push_swap->b)))
	{
		ft_putstr_fd("rb\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	rr(t_push_swap *push_swap)
{
	if (rotate(&(push_swap->a)) + rotate(&(push_swap->b)))
	{
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}
