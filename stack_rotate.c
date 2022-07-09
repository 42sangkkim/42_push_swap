/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:54:02 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/09 19:07:14 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

void	rotate(t_stack *stack)
{
	if (stack->top - stack->bot < 2)
		return ;
	if (stack->bot == 0)
	{
		stack->top += stack->size;
		stack->bot += stack->size;
	}
	stack->data[(stack->bot--) % stack->size]
		= stack->data[(--stack->top) % stack->size];
}

void	ra(t_stack *a, t_stack *b)
{
	(void)b;
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_stack *a, t_stack *b)
{
	(void)a;
	write(1, "rb\n", 3);
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	(void)b;
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}
