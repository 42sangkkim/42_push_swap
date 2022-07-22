/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:25:01 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 20:47:53 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	r_rotate(t_stack *stack)
{
	if (stack->len < 0)
		return (0);
	stack->top = stack->top->prev;
	return (1);
}

int	rra(t_push_swap *push_swap)
{
	if (r_rotate(&(push_swap->a)))
	{
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	rrb(t_push_swap *push_swap)
{
	if (r_rotate(&(push_swap->b)))
	{
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	rrr(t_push_swap *push_swap)
{
	if (r_rotate(&(push_swap->a)) + r_rotate(&(push_swap->b)))
	{
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}
