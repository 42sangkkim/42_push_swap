/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:31:40 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 13:40:32 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

void	op_sa(t_stack *a, t_stack *b, size_t n)
{
	int	tmp;

	(void)b;
	if (n % 2 && a->len > 1)
	{
		tmp = a->top->value;
		a->top->value = a->top->next->value;
		a->top->next->value = tmp;
		write(1, "sa\n", 3);
	}
}

void	op_sb(t_stack *a, t_stack *b, size_t n)
{
	int	tmp;

	(void)a;
	if (n % 2 && b->len > 1)
	{
		tmp = b->top->value;
		b->top->value = b->top->next->value;
		b->top->next->value = tmp;
		write(1, "sb\n", 3);
	}
}

void	op_ss(t_stack *a, t_stack *b, size_t n)
{
	int	tmp;

	(void)b;
	if (n % 2 && (a->len > 1 || b->len > 1))
	{
		if (a->len > 1)
		{
			tmp = a->top->value;
			a->top->value = a->top->next->value;
			a->top->next->value = tmp;
		}
		if (b->len > 1)
		{
			tmp = b->top->value;
			b->top->value = b->top->next->value;
			b->top->next->value = tmp;
		}
		write(1, "ss\n", 3);
	}
}
