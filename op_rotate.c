/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:50:21 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 15:50:17 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "operate.h"

void	op_rra(t_stack *a, t_stack *b, size_t n);
void	op_rrb(t_stack *a, t_stack *b, size_t n);

void	op_ra(t_stack *a, t_stack *b, size_t n)
{
	if (a->len < 2)
		return ;
	n %= a->len;
	if (2 * n > a->len)
		op_rra(a, b, a->len - n);
	else
	{
		while (n--)
		{
			a->top = a->top->next;
			write(1, "ra\n", 3);
		}
	}
}

void	op_rb(t_stack *a, t_stack *b, size_t n)
{
	if (b->len < 2)
		return ;
	n %= b->len;
	if (2 * n > b->len)
		op_rrb(a, b, b->len - n);
	else
	{
		while (n--)
		{
			b->top = b->top->next;
			write(1, "rb\n", 3);
		}
	}
}

void	op_rr(t_stack *a, t_stack *b, size_t n)
{
	if (a->len < 2 && b->len < 2)
		return ;
	else
	{
		while (n--)
		{
			a->top = a->top->next;
			b->top = b->top->next;
			write(1, "rr\n", 3);
		}
	}
}
