/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:47:31 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/09 18:58:10 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top - stack->bot < 2)
		return ;
	tmp = stack->data[(stack->top - 2) % stack->size];
	stack->data[(stack->top - 2) % stack->size]
		= stack->data[(stack->top - 1) % stack->size];
	stack->data[(stack->top - 1) % stack->size] = tmp;
}

void	sa(t_stack *a, t_stack *b)
{
	(void)b;
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_stack *a, t_stack *b)
{
	(void)a;
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}
