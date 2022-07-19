/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:39:27 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/19 16:07:39 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

#define OFFSET 0xFFFFFFFFL


void	atop_merge(t_stack *a, t_stack *b, size_t len);
void	abot_merge(t_stack *a, t_stack *b, size_t len);
void	btop_merge(t_stack *a, t_stack *b, size_t len);
void	bbot_merge(t_stack *a, t_stack *b, size_t len);

void	atop_merge(t_stack *a, t_stack *b, size_t len)
{
	size_t	group[3];
	long	tops[3];

	if (len < 2)
		return ;
	group[0] = len / 3;
	group[1] = len / 3;
	group[2] = len - (len / 3) * 2;
	abot_merge(a, b, group[0]);
	btop_merge(a, b, group[1]);
	bbot_merge(a, b, group[2]);
	tops[0] = (group[0] > 0) * ((long)a->top->prev->value + OFFSET);
	tops[1] = (group[1] > 0) * ((long)b->top->value + OFFSET);
	tops[2] = (group[2] > 0) * ((long)b->top->prev->value + OFFSET);
	while (group[0] + group[1] + group[2])
	{
		if (tops[0] >= tops[1] && tops[0] >= tops[2])
		{
			operation(a, b, rra, 1);
			tops[0] = (--group[0] > 0) * ((long)a->top->prev->value + OFFSET);
		}
		else if (tops[1] >= tops[2])
		{
			operation(a, b, pa, 1);
			tops[1] = (--group[1] > 0) * ((long)b->top->value + OFFSET);
		}
		else
		{
			operation(a, b, rrb, 1);
			operation(a, b, pa, 1);
			tops[2] = (--group[2] > 0) * ((long)b->top->prev->value + OFFSET);
		}
	}
}

void	abot_merge(t_stack *a, t_stack *b, size_t len)
{
	size_t	group[3];
	long	tops[3];

	if (len < 2)
		return ;
	group[0] = len / 3;
	group[1] = len / 3;
	group[2] = len - (len / 3) * 2;
	atop_merge(a, b, group[0]);
	btop_merge(a, b, group[1]);
	bbot_merge(a, b, group[2]);
	tops[0] = (group[0] > 0) * ((long)a->top->value + OFFSET);
	tops[1] = (group[1] > 0) * ((long)b->top->value + OFFSET);
	tops[2] = (group[2] > 0) * ((long)b->top->prev->value + OFFSET);
	while (group[0] + group[1] + group[2])
	{
		if (tops[0] <= tops[1] && tops[0] <= tops[2])
		{
			operation(a, b, ra, 1);
			tops[0] = (--group[0] > 0) * ((long)a->top->value + OFFSET);
		}
		else if (tops[1] <= tops[2])
		{
			operation(a, b, pa, 1);
			operation(a, b, ra, 1);
			tops[1] = (--group[1] > 0) * ((long)b->top->value + OFFSET);
		}
		else
		{
			operation(a, b, rrb, 1);
			operation(a, b, pa, 1);
			operation(a, b, ra, 1);
			tops[2] = (--group[2] > 0) * ((long)b->top->prev->value + OFFSET);
		}
	}
}

void	btop_merge(t_stack *a, t_stack *b, size_t len)
{
	size_t	group[3];
	long	tops[3];

	if (len < 2)
		return ;
	group[0] = len / 3;
	group[1] = len / 3;
	group[2] = len - (len / 3) * 2;
	bbot_merge(a, b, group[0]);
	atop_merge(a, b, group[1]);
	abot_merge(a, b, group[2]);
	tops[0] = (group[0] > 0) * ((long)b->top->prev->value + OFFSET);
	tops[1] = (group[1] > 0) * ((long)a->top->value + OFFSET);
	tops[2] = (group[2] > 0) * ((long)a->top->prev->value + OFFSET);
	while (group[0] + group[1] + group[2])
	{
		if (tops[0] <= tops[1] && tops[0] <= tops[2])
		{
			operation(a, b, rrb, 1);
			tops[0] = (--group[0] > 0) * ((long)b->top->prev->value + OFFSET);
		}
		else if (tops[1] <= tops[2])
		{
			operation(a, b, pb, 1);
			tops[1] = (--group[1] > 0) * ((long)a->top->value + OFFSET);
		}
		else
		{
			operation(a, b, rra, 1);
			operation(a, b, pb, 1);
			tops[2] = (--group[2] > 0) * ((long)a->top->prev->value + OFFSET);
		}
	}
}

void	bbot_merge(t_stack *a, t_stack *b, size_t len)
{
	size_t	group[3];
	long	tops[3];

	if (len < 2)
		return ;
	group[0] = len / 3;
	group[1] = len / 3;
	group[2] = len - (len / 3) * 2;
	btop_merge(a, b, group[0]);
	atop_merge(a, b, group[1]);
	abot_merge(a, b, group[2]);
	tops[0] = (group[0] > 0) * ((long)b->top->value + OFFSET);
	tops[1] = (group[1] > 0) * ((long)a->top->value + OFFSET);
	tops[2] = (group[2] > 0) * ((long)a->top->prev->value + OFFSET);
	while (group[0] + group[1] + group[2])
	{
		if (tops[0] >= tops[1] && tops[0] >= tops[2])
		{
			operation(a, b, rb, 1);
			tops[0] = (--group[0] > 0) * ((long)b->top->value + OFFSET);
		}
		else if (tops[1] >= tops[2])
		{
			operation(a, b, pb, 1);
			operation(a, b, rb, 1);
			tops[1] = (--group[1] > 0) * ((long)a->top->value + OFFSET);
		}
		else
		{
			operation(a, b, rra, 1);
			operation(a, b, pb, 1);
			operation(a, b, rb, 1);
			tops[2] = (--group[2] > 0) * ((long)a->top->prev->value + OFFSET);
		}
	}
}
