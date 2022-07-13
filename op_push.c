/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:41:19 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/13 13:46:26 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"

void	op_pa(t_stack *a, t_stack *b, size_t n)
{
	t_node	*tmp;

	if (n > b->len)
		n = b->len;
	while (n--)
	{
		*tmp = b->top;
		b->top->prev->next = b->top->next;
		b->top->next->prev = b->top->prev;
		b->top = b->top->next;
		a->top->prev->next = tmp;
		a->top->prev = tmp;
		a->top = tmp;
		write(1, "pa\n", 3);
	}
}

void	op_pb(t_stack *a, t_stack *b, size_t n)
{
	t_node	*tmp;

	if (n > a->len)
		n = a->len;
	while (n--)
	{
		*tmp = a->top;
		a->top->prev->next = a->top->next;
		a->top->next->prev = a->top->prev;
		a->top = a->top->next;
		b->top->prev->next = tmp;
		b->top->prev = tmp;
		b->top = tmp;
		write(1, "pb\n", 3);
	}
}

