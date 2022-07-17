/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:15:25 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 23:29:38 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	quick_sort_a(a, b, a-len);
}

void	quick_sort_a(t_stack *a, t_stack *b, size_t len)
{
	int		pivot;
	size_t	group_len[2];

	if (is_sorted(a, len))
		return ;
	else
	{
		pivot = a->top->value;
		group_len[0] = 0;
		group_len[1] = 0;
		while (len--)
		{
			if (a->top->value >= pivot)
			{
				operation(a, b, "ra", 1);
				group_len[0]++;
			}
			else
			{
				operation(a, b, "pb", 1);
				group_len[1]++;
			}
		}
		// sort group 0
		operation(a, b, "rra", group_len[0]);
		quick_sort_a(a, b, group_len[0]);
		// sort group 1
		quick_sort_b(a, b, group_len[1]);
		operation(a, b, "pa", group_len[1]);
	}
}

void	quick_sort_b(t_stack *a, t_stack *b, size_t len)
{
	int		pivot;
	size_t	group_len[2];

	if (is_rev_sorted(b, len))
		return ;
	else
	{
		pivot = b->top->value;
		group_len[0] = 0;
		group_len[1] = 0;
		while (len--)
		{
			if (b->top->value <= pivot)
			{
				operation(a, b, "rb", 1);
				group_len[0]++;
			}
			else
			{
				operation(a, b, "pa", 1);
				group_len[1]++;
			}
		}
		// sort group 0
		operation(a, b, "rrb", gourp_len[0]);
		quick_sort_b(a, b, group_len[0]);
		// sort group 1
		quick_sort_a(a, b, group_len[1]);
		operation(a, b, "pb", group_len[1]);
	}
}
