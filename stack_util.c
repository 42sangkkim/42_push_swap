/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:12:29 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 10:49:54 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
