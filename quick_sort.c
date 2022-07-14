/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:08:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/14 16:14:48 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operate.h"

void	quick_sort(t_stack *a, t_stack *b, size_t n);
void	quick_separate(t_stack *a, t_stack *b, int n, size_t group_len[3]);

int	sort_stack(t_stack *a, t_stack *b)
{
	quick_sort(a, b, a->len);
	return (0);
}

void	quick_sort(t_stack *a, t_stack *b, size_t n)
{
	size_t	group_len[3];

	if (n < 2)
		return ;
	group_len[0] = 0;
	group_len[1] = 0;
	group_len[2] = 0;
	quick_separate(a, b, n, group_len);
	operate(a, b, OP_RRA, group_len[0]);
	quick_sort(a, b, group_len[0]);
	operate(a, b, OP_PA, group_len[1]);
	quick_sort(a, b, group_len[1]);
	operate(a, b, OP_RRB, group_len[2]);
	operate(a, b, OP_PA, group_len[2]);
	quick_sort(a, b, group_len[2]);
}

void	quick_separate(t_stack *a, t_stack *b, int n, size_t group_len[3])
{
	int	pivot1;
	int	pivot2;

	pivot1 = a->top->value;
	pivot2 = a->top->next->value;
	while (n--)
	{
		if (a->top->value >= pivot1 && a->top->value >= pivot2)
		{
			operate(a, b, OP_RA, 1);
			group_len[0]++;
		}
		else if (a->top->value >= pivot1 || a->top->value >= pivot2)
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
}
