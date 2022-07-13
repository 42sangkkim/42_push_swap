/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:50:21 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 13:11:28 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	op_rotate(t_stack *a, t_stack *b, e_op op, size_t n)
{
	if (op == ra && a->len > 1)
	{
		n %= a->len;
		if (n >= a->len / 2 + 1)
			op_r_rotate(a, b, rra, a->len - n);
		else
		{
			rotate(a, n);
			while (n--)
				write(1, "ra\n", 3);
		}
	}
	else if (op == rb && b->len > 1)
	{
		n %= b->len;
		if (n >= b->len / 2 + 1)
			op_r_rotate(a, b, rrb, a->len - n);
		else
		{
			rotate(b, n);
			while (n--)
				write(1, "rb\n", 3);
		}
	}
	else if (op == rr && (a->len > 1 || b->len > 1))
	{
		rotate(a, n);
		rotate(b, n);
		while (n--)
			write(1, "rr\n", 3);
	}
}

void	op_r_rotate(t_stack *a, t_stack *b, e_op op, size_t n)
{
	if (op == rra && a->len > 1)
	{
		n %= a->len;
		if (n >= a->len / 2 + 1)
			op_rotate(a, b, rra, a->len - n);
		else
		{
			r_rotate(a, n);
			while (n--)
				write(1, "rra\n", 4);
		}
	}
	else if (op == rrb && b->len > 1)
	{
		n %= b->len;
		if (n >= b->len / 2 + 1)
			op_rotate(a, b, rrb, a->len - n);
		else
		{
			r_rotate(b, n);
			while (n--)
				write(1, "rrb\n", 4);
		}
	}
	else if (op == rrr && (a->len > 1 || b->len > 1))
	{
		while (n--)
		{
			if (r_rotate(a, 1) + r_rotate(b, 1))
				write(1, "rrr\n", 4);
		}
	}
}

size_t	rotate(t_stack *stack, size_t n);
{
	size_t	i;

	if (stack->len < 2)
		return (0);
	else
	{
		i = 0;
		while (i++ < n)
			stack->top = stack->top->next;
		return (n);
	}
}

size_t	r_rotate(t_stack *stack, size_t n)
{
	size_t	i;

	if (stack->len < 2)
		return (0);
	else
	{
		i = 0;
		while (i++ < n)
			stack->top = stack->top->prev;
		return (n);
	}
}
