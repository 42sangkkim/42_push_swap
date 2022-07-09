/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:47:31 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/09 18:57:56 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

void	push(t_stack *stack_dst, t_stack *stack_src)
{
	if (stack_src->top == stack_src->bot)
		return ;
	stack_dst->data[(stack_dst->top++) % stack_dst->size]
		= stack_src->data[(--stack_src->top) % stack_src->size];
}

void	pa(t_stack *a, t_stack *b)
{
	write(1, "pa\n", 3);
	push(a, b);
}

void	pb(t_stack *a, t_stack *b)
{
	write(1, "pb\n", 3);
	push(b, a);
}
