/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:12:29 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/12 17:17:22 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	swap(t_stack *stack)
{
	int	tmp_val;

	if (stack->len >= 2)
	{
		tmp_val = stack->top->value;
		stack->top->value = stack->top->next->value;
		stack->top->next->value = tmp_val;
	}
	return (0);
}

int	rotate(t_stack *stack)
{
	if (stack->len > 0)
		stack->top = stack->top->next;
	return (0);
}

int	r_rotate(t_stack *stack)
{
	if (stack->len > 0)
		stack->top = stack->top->prev;
	return (0);
}

int	is_sorted(t_stack stack)
{
	int		*array;
	size_t	i;
	size_t	j;

	array = to_array(&stack);
	if (!array)
		return (-1);
	i = 0;
	while (i < stack.len)
	{
		j = i + 1;
		while (j < stack.len)
		{
			if (array[i] > array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
