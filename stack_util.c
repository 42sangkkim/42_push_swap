/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:12:29 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/14 13:43:42 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_sorted(t_stack *stack, size_t n)
{
	int		*array;
	size_t	i;

	array = to_array(stack);
	if (!array)
		return (-1);
	if (n > stack->len)
		n = stack->len;
	i = 0;
	while (i + 1 < n)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_rev_sorted(t_stack *stack, size_t n)
{
	int		*array;
	size_t	i;

	array = to_array(stack);
	if (!array)
		return (-1);
	if (n > stack->len)
		n = stack->len;
	i = 0;
	while (i + 1 < n)
	{
		if (array[i] < array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
