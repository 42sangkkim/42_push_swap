/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:04:05 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/21 21:59:36 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_node(t_stack *stack, t_node *node);
int	pop_node(t_stack *stack, t_node **node_ptr);

static int	push(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (src->len == 0)
		return (0);
	pop_node(src, &node);
	push_node(dst, node);
	return (1);
}

int	pa(t_push_swap *push_swap)
{
	if (push(&(push_swap->a), &(push_swap->b)))
	{
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	pb(t_push_swap *push_swap)
{
	if (push(&(push_swap->b), &(push_swap->a)))
	{
		ft_putstr_fd("pb\n", STDOUT_FILENO);
		return (1);
	}
	return (0);
}
