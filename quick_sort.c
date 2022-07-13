/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:08:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 21:50:05 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operate.h"

void	quick_sort_a(t_stack *a, t_stack *b, size_t n);

int	sort_stack(t_stack *a, t_stack *b)
{
	quick_sort_a(a, b, a->len);
	return (0);
}

void	quick_sort_a(t_stack *a, t_stack *b, size_t n)
{
	int		pivot[2];
	size_t	group_len[3];

	if (n < 2)
		return ;
	pivot[0] = a->top->value;
	pivot[1] = a->top->next->value;
	group_len[0] = 0;
	group_len[1] = 0;
	group_len[2] = 0;
	while (n--)
	{
		if (a->top->value >= pivot[0] && a->top->value >= pivot[1])
		{
			operate(a, b, OP_RA, 1);
			group_len[0]++;
		}
		else if (a->top->value >= pivot[0] || a->top->value >= pivot[1])
		{
			operate(a, b, OP_PB, 1);
			group_len[1]++;
		}
		else
		{
			operate(a, b, OP_PB, 1);
			operate(a, b, OP_RB, 1);
			group_len[2]++;
		}
	}
	// sort 0
	operate(a, b, OP_RRA, group_len[0]);
	quick_sort_a(a, b, group_len[0]);
	// sort 1
	operate(a, b, OP_PA, group_len[1]);
	quick_sort_a(a, b, group_len[1]);
	// sort 2
	operate(a, b, OP_RRB, group_len[2]);
	operate(a, b, OP_PA, group_len[2]);
	quick_sort_a(a, b, group_len[2]);
}
