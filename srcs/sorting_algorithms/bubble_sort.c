/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:38:24 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 15:56:58 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operate.h"

int	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack_a->len)
	{
		j = i;
		while (j + 1 < stack_a->len)
		{
			if (stack_a->top->value > stack_a->top->next->value)
				operate(stack_a, stack_b, OP_SA, 1);
			operate(stack_a, stack_b, OP_RA, 1);
			j++;
		}
		operate(stack_a, stack_b, OP_RRA, j - i);
		i++;
	}
	return (0);
}
