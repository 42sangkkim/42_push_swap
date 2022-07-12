/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:38:24 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 17:02:29 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				exe_operation(stack_a, stack_b, "sa");
			exe_operation(stack_a, stack_b, "ra");
			j++;
		}
		while (j-- > i)
			exe_operation(stack_a, stack_b, "rra");
		i++;
	}
	return (0);
}
