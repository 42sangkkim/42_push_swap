/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:52:37 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 17:09:00 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int		calc_direction(size_t pow, size_t i);
size_t	calc_amount(size_t pow, size_t i, size_t n);

int		make_triangle_to_a(t_stack *a, t_stack *b, int dir, size_t amt);
int		make_triangle4_to_a(t_stack *a, t_stack *b, int dir);
int		make_triangle_to_b(t_stack *a, t_stack *b, int dir, size_t amt);
int		make_triangle4_to_b(t_stack *a, t_stack *b, int dir);

void	init_depth(t_stack *a, t_stack *b, size_t n, int depth)
{
	size_t	i;
	size_t	pow;
	int		direction;
	size_t	amount;

	pow = ft_pow(3, depth);
	if (depth % 2 == 0)
	{
		while (a->len)
			pb(a, b, 1);
	}
	i = 0;
	while (i < pow)
	{
		direction = calc_direction(pow, i);
		amount = calc_amount(pow, i, n);
		if (depth % 2 == 1)
			make_triangle_to_b(a, b, direction, amount);
		else
			make_triangle_to_a(a, b, direction, amount);
		i++;
	}
}

int	make_triangle_to_a(t_stack *a, t_stack *b, int dir, size_t amt)
{
	if (amt == 1)
		return (pa(a, b, 1));
	else if (amt == 2)
	{
		if ((b->top->value > b->top->next->value) != dir)
			sb(a, b, 1);
		return (pa(a, b, 1) && pa(a, b, 1));
	}
	else if (amt == 3)
	{
		if ((b->top->value > b->top->next->value) != dir)
			sb(a, b, 1);
		if ((b->top->prev->value > b->top->value) == dir)
			return (rrb(a, b, 1) && pa(a, b, 1) && pa(a, b, 1) && pa(a, b, 1));
		else if ((b->top->prev->value > b->top->next->value) == dir)
			return (pa(a, b, 1) && rrb(a, b, 1) && pa(a, b, 1) && pa(a, b, 1));
		else
			return (pa(a, b, 1) && pa(a, b, 1) && rrb(a, b, 1) && pa(a, b, 1));
	}
	else
		return (make_triangle4_to_a(a, b, dir));
}

int	make_triangle4_to_a(t_stack *a, t_stack *b, int dir)
{
	if ((b->top->value > b->top->next->value) != dir)
		sb(a, b, 1);
	if ((b->top->value > b->top->next->next->value) == dir
		&& (b->top->value > b->top->prev->value) == dir)
		return (pa(a, b, 1) && make_triangle_to_a(a, b, dir, 3));
	else if ((b->top->prev->value > b->top->value) == dir
		&& (b->top->prev->value > b->top->next->next->value) == dir)
	{
		if ((b->top->value > b->top->next->next->value) == dir)
			return (rrb(a, b, 1) && pa(a, b, 1) && pa(a, b, 1) \
				&& make_triangle_to_a(a, b, dir, 2));
		else
			return (rrb(a, b, 1) && pa(a, b, 1) && pa(a, b, 1) \
			&& sb(a, b, 1) && pa(a, b, 1) && sa(a, b, 1) && pa(a, b, 1));
	}
	else if (pa(a, b, 1) && sb(a, b, 1) && pa(a, b, 1) && sa(a, b, 1))
	{
		if ((b->top->value > b->top->prev->value) == dir)
			return (pa(a, b, 1) && rrb(a, b, 1) && pa(a, b, 1));
		else if ((a->top->value > b->top->prev->value) == dir)
			return (rrb(a, b, 1) && pa(a, b, 1) && pa(a, b, 1));
		else
			return (rrb(a, b, 1) && pa(a, b, 1) && sa(a, b, 1) && pa(a, b, 1));
	}
	return (0);
}

int	make_triangle_to_b(t_stack *a, t_stack *b, int dir, size_t amt)
{
	if (amt == 1)
		return (pb(a, b, 1));
	else if (amt == 2)
	{
		if ((a->top->value > a->top->next->value) != dir)
			sa(a, b, 1);
		return (pb(a, b, 1) && pb(a, b, 1));
	}
	else if (amt == 3)
	{
		if ((a->top->value > a->top->next->value) != dir)
			sa(a, b, 1);
		if ((a->top->prev->value > a->top->value) == dir)
			return (rra(a, b, 1) && pb(a, b, 1) && pb(a, b, 1) && pb(a, b, 1));
		else if ((a->top->prev->value > a->top->next->value) == dir)
			return (pb(a, b, 1) && rra(a, b, 1) && pb(a, b, 1) && pb(a, b, 1));
		else
			return (pb(a, b, 1) && pb(a, b, 1) && rra(a, b, 1) && pb(a, b, 1));
	}
	else
		return (make_triangle4_to_b(a, b, dir));
}

int	make_triangle4_to_b(t_stack *a, t_stack *b, int dir)
{
	if ((a->top->value > a->top->next->value) != dir)
		sa(a, b, 1);
	if ((a->top->value > a->top->next->next->value) == dir
		&& (a->top->value > a->top->prev->value) == dir)
		return (pb(a, b, 1) && make_triangle_to_b(a, b, dir, 3));
	else if ((a->top->prev->value > a->top->value) == dir
		&& (a->top->prev->value > a->top->next->next->value) == dir)
	{
		if ((a->top->value > a->top->next->next->value) == dir)
			return (rra(a, b, 1) && pb(a, b, 1) && pb(a, b, 1) \
				&& make_triangle_to_b(a, b, dir, 2));
		else
			return (rra(a, b, 1) && pb(a, b, 1) && pb(a, b, 1) \
			&& sa(a, b, 1) && pb(a, b, 1) && sb(a, b, 1) && pb(a, b, 1));
	}
	else if (pb(a, b, 1) && sa(a, b, 1) && pb(a, b, 1) && sb(a, b, 1))
	{
		if ((a->top->value > a->top->prev->value) == dir)
			return (pb(a, b, 1) && rra(a, b, 1) && pb(a, b, 1));
		else if ((b->top->value > a->top->prev->value) == dir)
			return (rra(a, b, 1) && pb(a, b, 1) && pb(a, b, 1));
		else
			return (rra(a, b, 1) && pb(a, b, 1) && sb(a, b, 1) && pb(a, b, 1));
	}
	return (0);
}
