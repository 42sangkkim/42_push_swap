/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:58:58 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/09 22:46:07 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

void	reverse_rotate(t_stack *stack)
{
	if (stack->top - stack->bot < 2)
		return ;
	stack->data[(stack->top++) % stack->size]
		= stack->data[(stack->bot++) % stack->size];
	if (stack->bot > stack->size)
	{
		stack->top -= stack->size;
		stack->bot -= stack->size;
	}
}

void	rra(t_stack *a, t_stack *b)
{
	(void)b;
	write(1, "rra\n", 4);
	reverse_rotate(a);
}

void	rrb(t_stack *a, t_stack *b)
{
	(void)a;
	write(1, "rrb\n", 4);
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	write(1, "rrr\n", 4);
	reverse_rotate(a);
	reverse_rotate(b);
}
