/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:21:35 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/24 15:19:47 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"

int	tiny_sort_a(t_push_swap *ps);
int	tiny_rev_sort_b(t_push_swap *ps);
int	tiny_merge(t_push_swap *ps);

int	tiny_sort(t_push_swap *ps)
{
	size_t	i;

	if (ps->a.len <= 3)
		return (tiny_sort_a(ps));
	else if (ps->a.len <= 6)
	{
		i = ps->a.len - 3;
		while (i--)
			pb(ps, 1);
		tiny_sort_a(ps);
		tiny_rev_sort_b(ps);
		tiny_merge(ps);
		return (1);
	}
	else
		return (-1);
}

int	tiny_sort_a(t_push_swap *ps)
{
	if (ps->a.len <= 1)
		return (1);
	else if (ps->a.len == 2)
		return (ps->a.top->value < ps->a.top->next->value || sa(ps, 1));
	else if (ps->a.len == 3)
	{
		if (ps->a.top->value > ps->a.top->next->value
			&& ps->a.top->value > ps->a.top->prev->value)
			ra(ps, 1);
		else if (ps->a.top->next->value > ps->a.top->prev->value)
			rra(ps, 1);
		if (ps->a.top->value > ps->a.top->next->value)
			sa(ps, 1);
		return (1);
	}
	else
		return (0);
}

int	tiny_rev_sort_b(t_push_swap *ps)
{
	if (ps->b.len <= 1)
		return (1);
	else if (ps->b.len == 2)
		return (ps->b.top->value > ps->b.top->next->value || sb(ps, 1));
	else if (ps->b.len == 3)
	{
		if (ps->b.top->value < ps->b.top->next->value
			&& ps->b.top->value < ps->b.top->prev->value)
			rb(ps, 1);
		else if (ps->b.top->next->value < ps->b.top->prev->value)
			rrb(ps, 1);
		if (ps->b.top->value < ps->b.top->next->value)
			sb(ps, 1);
		return (1);
	}
	else
		return (0);
}

int	tiny_merge(t_push_swap *ps)
{
	size_t	rest[2];

	rest[0] = ps->a.len;
	rest[1] = ps->b.len;
	while (rest[0] + rest[1])
	{
		if (!rest[1])
			rest[0] -= rra(ps, 1);
		else if (!rest[0])
			rest[1] -= pa(ps, 1);
		else if (ps->a.top->prev->value > ps->b.top->value)
			rest[0] -= rra(ps, 1);
		else
			rest[1] -= pa(ps, 1);
	}
	return (1);
}
