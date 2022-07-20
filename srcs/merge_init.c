/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:52:37 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/20 23:17:28 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void	init_depth(t_stack *a, t_stack *b, size_t n, int depth)
{
	size_t	i;
	size_t	pow;

	pow = ft_pow(3, depth);
	i = 0;
	if (depth % 2 == 1)
	{
		while (i < pow)
		{
			make_triangle_to_b(a, b,
				calc_direction(pow / 3, i), calc_amount(pow / 3, i, n));
			i++;
		}
	}
	else
	{
		operation(a, b, pb, a->len);
		while (i < pow)
		{
			make_triangle_to_a(a, b,
				calc_direction(pow / 3, i), calc_amount(pow / 3, i, n));
			i++;
		}
	}
}

make_triangle_to_a(t_stack *a, t_stack *b, int dir, size_t amt)
{
	if (amt == 1)
		operation(a, b, pa, 1);
	else if (amt == 2)
	{
		if ((b->top->value > b->top->next->value) != dir)
			operation(a, b, sb, 1);
		operation(a, b, pa, 2);
	}
	else if (amt == 3)
	{
		if ((b->top->value > b->top->next->value) == dir
			&& (b->top->value > b->top->prev->value) == dir
			&& (b->top->next->value > b->top->prev->value) == dir)
		{
			operation(a, b, pa, 2);
			operation(a, b, rrb, 1);
			operation(a, b, pa, 1);
		}
		else if ((b->top->value > b->top->next->value) == dir
			&& (b->top->value > b->top->prev->value) == dir
			&& (b->top->next->value > b->top->prev->value) != dir)
		{
			operation(a, b, pa, 1);
			operation(a, b, rrb, 1);
			operation(a, b, pa, 2);
		}
		else if ((b->top->next->value > b->top->prev->value) == dir) // next is first
		{
			operation(a, b, sa, 1);
			operation(a, b, pa, 1);
			if ((b->top->value > b->top->prev->value) == dir)
			{
				operation(a, b, pa, 1);
				operation(a, b, rrb, 1);
				operation(a, b, pa, 1);
			}
			else
			{
				operation(a, b, rrb, 1);
				operation(a, b, pa, 2);
			}
		}
		else // prev is first
		{
			operation(a, b, rrb, 1);
			operation(a, b, pa, 1);
			make_triangle_to_a(a, b, dir, 2);
		}
	}
	else if (amt == 4)
	{
		if ()
	}
}

make_triangle_to_b(t_stack *a, t_stack *b, int dir, size_t amt)
{
	if (amt == 1)
		operation(a, b, pb, 1);
	else if (amt == 2)
	{
		if ((a->top->value > a->top->next->value) != dir)
			operation(a, b, sa, 1);
		operation(a, b, pb, 2);
	}
	else if (amt == 3)
	{
	}
	else if (amt == 4)
	{

	}
}