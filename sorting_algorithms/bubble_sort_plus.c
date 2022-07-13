/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:38:24 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 18:31:16 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operate.h"

int	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	size_t	max;
	size_t	min;
	size_t	i;

	(void)stack_b;
	max = stack_a->len - 1;
	min = 0;
	i = 0;
	while (min < max)
	{
		while (i < max)
		{
			if (stack_a->top->value > stack_a->top->next->value)
				operate(stack_a, stack_b, OP_SA, 1);
			operate(stack_a, stack_b, OP_RA, 1);
			i++;
		}
		max--;
		while (min < i)
		{
			operate(stack_a, stack_b, OP_RRA, 1);
			i--;
			if (stack_a->top->value > stack_a->top->next->value)
				operate(stack_a, stack_b, OP_SA, 1);
		}
		min++;
	}
	operate(stack_a, stack_b, OP_RRA, min - 1);
	return (0);
}
