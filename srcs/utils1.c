/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:27:00 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/23 21:37:48 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_sorted(t_stack *stack, size_t n)
{
	t_node	*node;

	if (n > stack->len)
		n = stack->len;
	node = stack->top;
	while (--n)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	ft_pow(int a, int b)
{
	int	pow;

	pow = 1;
	while (b--)
		pow *= a;
	return (pow);
}

int	value_of(t_stack *stack, int i)
{
	t_node	*node;

	if (stack->len == 0)
		return (0);
	node = stack->top;
	if (i < 0)
	{
		while (i++)
			node = node->prev;
	}
	else
	{
		while (i--)
			node = node->next;
	}
	return (node->value);
}
