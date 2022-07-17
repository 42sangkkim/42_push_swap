/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:17:36 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/17 12:17:38 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void	op_pa(t_stack *a, t_stack *b, t_op op, size_t n)
{
	t_node	*node;

	while (n--)
	{
		if (pop_node(b, &node) == 0 && push_node(a, node) == 0)
			write(1, "pa\n", 3);
	}
}

void	op_pb(t_stack *a, t_stack *b, t_op op, size_t n)
{
	t_node	*node;

	while (n--)
	{
		if (pop_node(a, &node) == 0 && push_node(b, node) == 0)
			write(1, "pb\n", 3);
	}
}

void	op_ra(t_stack *a, t_stack *b, t_op op, size_t n)
{
	(void)b;
	while (n--)
	{
		if (rotate(a))
			write(1, "ra\n", 3);
	}
}

void	op_rb(t_stack *a, t_stack *b, t_op op, size_t n)
{
	(void)a;
	while (n--)
	{
		if (rotate(b))
			write(1, "rb\n", 3);
	}
}

void	op_rr(t_stack *a, t_stack *b, t_op op, size_t n)
{
	while (n--)
	{
		if (rotate(a) + rotate(b))
			write(1, "rr\n", 3);
	}
}
