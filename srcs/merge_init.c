/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:52:37 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/22 17:48:32 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int		calc_direction(size_t pow, size_t i);
size_t	calc_amount(size_t pow, size_t i, size_t n);

int		make_triangle_to_a(t_push_swap *ps, int dir, size_t amt);
int		make_triangle4_to_a(t_push_swap *ps, int dir);
int		make_triangle_to_b(t_push_swap *ps, int dir, size_t amt);
int		make_triangle4_to_b(t_push_swap *ps, int dir);

void	init_depth(t_push_swap *push_swap, size_t n, int depth)
{
	size_t	i;
	size_t	pow;

	pow = ft_pow(3, depth);
	i = 0;
	if (depth % 2 == 1)
	{
		while (i < pow)
		{
			// print_push_swap(push_swap);
			make_triangle_to_b(push_swap,
				calc_direction(pow, i), calc_amount(pow, i, n));
			i++;
		}
	}
	else
	{
		while (pb(push_swap))
			;
		while (i < pow)
		{
			// print_push_swap(push_swap);
			make_triangle_to_a(push_swap,
				calc_direction(pow, i), calc_amount(pow, i, n));
			i++;
		}
	}
}

int	make_triangle_to_a(t_push_swap *ps, int dir, size_t amt)
{
	if (amt == 1)
		return (pa(ps));
	else if (amt == 2)
	{
		if ((ps->b.top->value > ps->b.top->next->value) != dir)
			sb(ps);
		return (pa(ps) && pa(ps));
	}
	else if (amt == 3)
	{
		if ((ps->b.top->value > ps->b.top->next->value) != dir)
			sb(ps);
		if ((ps->b.top->prev->value > ps->b.top->value) == dir)
			return (rrb(ps) && pa(ps) && pa(ps) && pa(ps));
		else if ((ps->b.top->prev->value > ps->b.top->next->value) == dir)
			return (pa(ps) && rrb(ps) && pa(ps) && pa(ps));
		else
			return (pa(ps) && pa(ps) && rrb(ps) && pa(ps) );
	}
	else
		return (make_triangle4_to_a(ps, dir));
}

int	make_triangle4_to_a(t_push_swap *ps, int dir)
{
	if ((ps->b.top->value > ps->b.top->next->value) != dir)
		sb(ps);
	if ((ps->b.top->value > ps->b.top->next->next->value) == dir
		&& (ps->b.top->value > ps->b.top->prev->value) == dir)
		return (pa(ps) && make_triangle_to_a(ps, dir, 3));
	else if ((ps->b.top->prev->value > ps->b.top->value) == dir
		&& (ps->b.top->prev->value > ps->b.top->next->next->value) == dir)
	{
		if ((ps->b.top->value > ps->b.top->next->next->value) == dir)
			return (
				rrb(ps) && pa(ps) && pa(ps) && make_triangle_to_a(ps, dir, 2));
		else
			return (rrb(ps) && pa(ps) && pa(ps) \
			&& sb(ps) && pa(ps) && sa(ps) && pa(ps));
	}
	else if (pa(ps) && sb(ps) && pa(ps) && sa(ps))
	{
		if ((ps->b.top->value > ps->b.top->prev->value) == dir)
			return (pa(ps) && rrb(ps) && pa(ps));
		else if ((ps->a.top->value > ps->b.top->prev->value) == dir)
			return (rrb(ps) && pa(ps) && pa(ps));
		else
			return (rrb(ps) && pa(ps) && sa(ps) && pa(ps));
	}
	return (0);
}

int	make_triangle_to_b(t_push_swap *ps, int dir, size_t amt)
{
	if (amt == 1)
		return (pb(ps));
	else if (amt == 2)
	{
		if ((ps->a.top->value > ps->a.top->next->value) != dir)
			sa(ps);
		return (pb(ps) && pb(ps));
	}
	else if (amt == 3)
	{
		if ((ps->a.top->value > ps->a.top->next->value) != dir)
			sa(ps);
		if ((ps->a.top->prev->value > ps->a.top->value) == dir)
			return (rra(ps) && pb(ps) && pb(ps) && pb(ps));
		else if ((ps->a.top->prev->value > ps->a.top->next->value) == dir)
			return (pb(ps) && rra(ps) && pb(ps) && pb(ps));
		else
			return (pb(ps) && pb(ps) && rra(ps) && pb(ps));
	}
	else
		return (make_triangle4_to_b(ps, dir));
}

int	make_triangle4_to_b(t_push_swap *ps, int dir)
{
	if ((ps->a.top->value > ps->a.top->next->value) != dir)
		sa(ps);
	if ((ps->a.top->value > ps->a.top->next->next->value) == dir
		&& (ps->a.top->value > ps->a.top->prev->value) == dir)
		return (pb(ps) && make_triangle_to_b(ps, dir, 3));
	else if ((ps->a.top->prev->value > ps->a.top->value) == dir
		&& (ps->a.top->prev->value > ps->a.top->next->next->value) == dir)
	{
		if ((ps->a.top->value > ps->a.top->next->next->value) == dir)
			return (
				rra(ps) && pb(ps) && pb(ps) && make_triangle_to_b(ps, dir, 2));
		else
			return (rra(ps) && pb(ps) && pb(ps) \
			&& sa(ps) && pb(ps) && sb(ps) && pb(ps));
	}
	else if (pb(ps) && sa(ps) && pb(ps) && sb(ps))
	{
		if ((ps->a.top->value > ps->a.top->prev->value) == dir)
			return (pb(ps) && rra(ps) && pb(ps));
		else if ((ps->b.top->value > ps->a.top->prev->value) == dir)
			return (rra(ps) && pb(ps) && pb(ps));
		else
			return (rra(ps) && pb(ps) && sb(ps) && pb(ps));
	}
	return (0);
}
