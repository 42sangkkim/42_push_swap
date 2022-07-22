/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:06:06 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 20:00:04 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "utils.h"

int		calc_direction(size_t pow, size_t i);
size_t	calc_amount(size_t pow, size_t i, size_t n);

void	merge_to_a(t_push_swap *ps, size_t pow, size_t n, size_t len_to_a);
void	merge_to_b(t_push_swap *ps, size_t pow, size_t n, size_t len_to_b);
void	make_triangle_a(t_push_swap *ps, int dir, size_t amt);
void	make_triangle_b(t_push_swap *ps, int dir, size_t amt);

void	merge_depth(t_push_swap *push_swap, size_t n, int depth)
{
	size_t	i;
	size_t	amt;
	size_t	pow;

	i = 0;
	amt = 0;
	pow = ft_pow(3, depth);
	while (i < pow)
		amt += calc_amount(pow * 3, 2 * pow + i++, n);
	if (depth % 2 == 0)
		merge_to_a(push_swap, pow, n, amt);
	else
		merge_to_b(push_swap, pow, n, amt);
}

void	merge_to_a(t_push_swap *ps, size_t pow, size_t n, size_t len_to_a)
{
	size_t	i;

	while (len_to_a--)
		pa(ps);
	i = 0;
	while (i < pow)
	{
		make_triangle_a(ps, calc_direction(pow, i), calc_amount(pow, i, n));
		i++;
	}
}

void	merge_to_b(t_push_swap *ps, size_t pow, size_t n, size_t len_to_b)
{
	size_t	i;

	while (len_to_b--)
		pb(ps);
	i = 0;
	while (i < pow)
	{
		make_triangle_b(ps, calc_direction(pow, i), calc_amount(pow, i, n));
		i++;
	}
}

void	make_triangle_a(t_push_swap *ps, int dir, size_t amt)
{
	size_t	rest[3];

	rest[0] = amt / 3;
	rest[1] = amt / 3 + (amt % 3 > 0);
	rest[2] = amt / 3 + (amt % 3 > 1);
	while (rest[0] + rest[1] + rest[2])
	{
		if (rest[0]
			&& (!rest[1]
				|| (ps->b.top->prev->value > ps->b.top->value) == dir)
			&& (!rest[2]
				|| (ps->b.top->prev->value > ps->a.top->prev->value) == dir))
			rest[0] -= (rrb(ps) && pa (ps)) > 0;
		else if (rest[1]
			&& (!rest[2]
				|| (ps->b.top->value > ps->a.top->prev->value) == dir))
			rest[1] -= pa(ps) > 0;
		else
			rest[2] -= rra(ps) > 0;
	}
}

void	make_triangle_b(t_push_swap *ps, int dir, size_t amt)
{
	size_t	rest[3];

	rest[0] = amt / 3;
	rest[1] = amt / 3 + (amt % 3 > 0);
	rest[2] = amt / 3 + (amt % 3 > 1);
	while (rest[0] + rest[1] + rest[2])
	{
		if (rest[0]
			&& (!rest[1]
				|| (ps->a.top->prev->value > ps->a.top->value) == dir)
			&& (!rest[2]
				|| (ps->a.top->prev->value > ps->b.top->prev->value) == dir))
			rest[0] -= (rra(ps) && pb (ps)) > 0;
		else if (rest[1]
			&& (!rest[2]
				|| (ps->a.top->value > ps->b.top->prev->value) == dir))
			rest[1] -= pb(ps) > 0;
		else
			rest[2] -= rrb(ps) > 0;
	}
}
