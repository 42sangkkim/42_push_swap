/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:25:43 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/09 22:50:07 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

t_stack	*new_stack(size_t size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack) + size * sizeof(int));
	if (!stack)
		return (NULL);
	stack->size = size;
	stack->top = 0;
	stack->bot = 0;
	return (stack);
}
